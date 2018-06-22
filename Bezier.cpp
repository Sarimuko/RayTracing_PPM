//
// Created by wangyihan on 2018/6/21.
//

#include "Bezier.h"
#include <math.h>

cv::Point2d Bezier::getCurve(double t)
{
    std::vector<cv::Point2d> tmp1, tmp2;
    tmp1 = controlPoints;
    for (int i=0;i<cpCnt - 1;i++)
    {
        int num = cpCnt - i - 1;
        for (int j=0;j< num;j++)
        {
            cv::Point2d p = t * tmp1[j] + (1 - t) * tmp1[j + 1];
            tmp2.push_back(p);
        }
        tmp1 = tmp2;
    }
    return tmp1[0];
}

cv::Point3d Bezier::getPoint(double t, double theta)
{
    return origin + py(t) * Dz + Dx * px(t) * cos(theta) + Dy * px(t) * sin(theta);

}

Hit Bezier::RayCast(Ray ray)
{
    //解方程 B(tb, theta) = ray.p0 + t * ray.pd;

    cv::Point3d P = ray.p0 - origin;
    cv::Point3d Pd = ray.pd;
    //O = O.transformedToNewAxis(Dx, Dy, Dz);
    Ray new_ray(P, Pd);
    //Solve t,u in the equations
    // P(t).x^2 = (P.x+u*Pd.x)^2 + (P.y+u*Pd.y)^2
    // P(t).y   = P.z + u*Pd.z;
    Polynomial eq;
    std::vector<std::complex<double>> ts;

    if (!sign(Pd.z)) {eq = (py - P.z); eq.roots(ts); }//防止溢出
    else {
        Polynomial nu = (py - P.z) / Pd.z;
        eq = pow(px, 2) - pow(P.x + nu * Pd.x, 2) - pow(P.y + nu * Pd.y, 2);
        eq.roots(ts);
    }//这里解出来的是beizier曲线的t

    double ans_t, ans_theta;
    Hit hit;
    hit.t = CONST::INF;

    for (auto c: ts)//枚举所有的根
    {
        //std::cout << c<<std::endl;
        if (sign(c.imag()))//虚根，舍掉
            continue;

        double t = c.real();
        if (sign(t - 1) > 0 || sign(t) < 0)//超出范围的根，舍掉
            continue;

        t = max(0., min(1, t));//将根划归到0，1区间

        double u;

        if (sign(Pd.z))
        {
            u = (py(t) - P.z)/Pd.z;
        }
        else
        {
            double r = px(t);

            cv::Point3d center(0, 0, py(t));
            double d = new_ray.dis2(center);
            //std::cout << "d: "<<d << "r * r: " << r * r<<std::endl;
            if (sign(d - r * r) > 0)//没有交点
                continue;

            cv::Point3d ll = center - hit.P;
            if (sign(hit.Pd.ddot(ll)) <= 0)
                continue;

            double l = P.x * P.x + P.y * P.y;

            //std::cout << "l: "<<l<<std::endl;
            double u0 = sqrt(l - d);
            double u1 = sqrt(r * r - d);

            u = u0 - u1;

        }

        if (sign(u) > 0 && u < hit.t)
        {
            hit.t = u;
            ans_t = t;
        }


    }

    if (hit.t < CONST::INF)
    {
        hit.valid = true;
        hit.P = ray.p0 + hit.t * ray.pd;
        hit.Pd = ray.pd;

        cv::Point3d Z(0, 0, 1);
        cv::Point3d X(hit.P.x - origin.x, hit.P.y - origin.y, 0);
        X = regu(X);

        //std::cout << X<<std::endl;

        hit.N = dpy(ans_t) * X - dpx(ans_t) * Z;
        hit.N = regu(hit.N);

        hit.Rd = getReflect(hit.Pd, hit.N);

        hit.deffuseR = rou_d;
        hit.reflectCoefficience = reflectR;
        hit.refractCoefficience = refractR;

        hit.r = r;
        hit.g = g;
        hit.b = b;


        hit.spec = spec;
        //std::cout << hit.N<<hit.P<<hit.Pd<<hit.Rd;

    }

    return hit;
}

bool Bezier::Intersect(Ray ray)
{
    Hit hit = RayCast(ray);

    return hit.valid;
}

std::pair<Polynomial, Polynomial> Bezier::P2d(int l, int n)
{
    if (n == 1)
        return std::pair<Polynomial, Polynomial>(controlPoints[l].x, controlPoints[l].y);
    std::pair<Polynomial, Polynomial> lhs = P2d(l, n - 1), rhs = P2d(l + 1, n - 1);
    return std::pair<Polynomial, Polynomial>(Polynomial(1, -1) * lhs.first  + Polynomial(0, 1) * rhs.first,
                                             Polynomial(1, -1) * lhs.second + Polynomial(0, 1) * rhs.second);
}

void Bezier::init()
{
    printf("initializing Bezier\n");

    std::pair<Polynomial, Polynomial> tmp = P2d(0, controlPoints.size());
    px = tmp.first; py = tmp.second;
    dpx = px.derivative(); dpy = py.derivative();

    Dz.x = Dz.y = Dx.y = Dx.z = Dy.x = Dy.z = 0;
    Dz.z = Dx.x = Dy.y = 1;

    /*for (auto point: controlPoints)
    {
        boundingBox.include()
    }*/
    //todo boundingbox


    /*printf("Test for Bezier: P(%.3f, %.3f)=(%.3f, %.3f, %.3f)\n", 0., 0., getPoint(0., 0.).x, getPoint(0., 0.).y, getPoint(0., 0.).z);
    printf("Test for Bezier: P(%.3f, %.3f)=(%.3f, %.3f, %.3f)\n", 0.5, 0.5 * CONST::pi, getPoint(0.5, 0.5 * CONST::pi).x, getPoint(0.5, 0.5 * CONST::pi).y, getPoint(0.5, 0.5 * CONST::pi).z);
    printf("Test for Bezier: P(%.3f, %.3f)=(%.3f, %.3f, %.3f)\n", 1, 0., getPoint(0., 0.).x, getPoint(0., 0.).y, getPoint(0., 0.).z);*/
    //printf("Test for Bezier: P(%.3f)=(%.3f, %.3f)\n", 0.5, px(0.5), py(0.5));
    //printf("Test for Bezier: P(%.3f)=(%.3f, %.3f)\n", 1., px(1), py(1));

    //std::cout << bbox << std::endl;
}

cv::Vec3b Bezier::getColor(cv::Point3d P)
{
    cv::Vec3b color;
    if (texture.data == NULL)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;

        return color;
    }
    return color;
}