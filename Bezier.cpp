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

    Ray new_ray(P, Pd);

    Polynomial eq;
    std::vector<std::complex<double>> roots;

    Hit hit;

    if (!boundingBox.intersect(ray)) return hit;

    if (!sign(Pd.z)) {eq = (py - P.z); eq.roots(roots); }//防止溢出
    else {
        Polynomial nu = (py - P.z) / Pd.z;
        eq = pow(px, 2) - pow(P.x + nu * Pd.x, 2) - pow(P.y + nu * Pd.y, 2);
        eq.roots(roots);
    }//这里解出来的是beizier曲线的t

    double ans_t, ans_theta;

    hit.t = CONST::INF;

    for (auto c: roots)//枚举所有的根
    {
        if (sign(c.imag()))//虚根，舍掉
            continue;

        double t = c.real();
        if (sign(t - 1) > 0 || sign(t) < 0)//超出范围的根，舍掉
            continue;

        t = max(0, min(1, t));//将根划归到0，1区间

        double tt;

        if (sign(Pd.z))
        {
            tt = (py(t) - P.z)/Pd.z;
        }
        else
        {
            double r = px(t);

            cv::Point3d center(0, 0, py(t));
            double d = new_ray.dis2(center);
            //std::cout << "d: "<<d << "r * r: " << r * r<<std::endl;
            if (sign(d - r * r) > 0)//没有交点
                continue;

            cv::Point3d ll = center - new_ray.p0;
            if (sign(ray.pd.ddot(ll)) <= 0)
                continue;

            double l = P.x * P.x + P.y * P.y;

            //std::cout << "l: "<<l<<std::endl;
            double t0 = sqrt(l - d);
            double t1 = sqrt(r * r - d);

            tt = t0 - t1;

        }

        if (sign(tt) > 0 && tt < hit.t)
        {
            hit.t = tt;
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

        hit.N = dpy(ans_t) * X - dpx(ans_t) * Z;
        hit.N = regu(hit.N);

        hit.Rd = getReflect(hit.Pd, hit.N);

        hit.deffuseR = rou_d;
        hit.reflectCoefficience = reflectR;
        hit.refractCoefficience = refractR;
        hit.spec = spec;

        hit.n0 = hit.n1 = 1;

        cv::Point3d nP = new_ray.p0 + new_ray.pd * hit.t;
        double px_v = px(ans_t);

        if (!sign(nP.x) && !sign(nP.y)) ans_theta = 0;
        else {
            ans_theta = atan2(nP.y, nP.x) + PI*(px_v < 0);
            if (ans_theta > PI) ans_theta -= 2 * PI;
        }

        cv::Vec3b color = getColor(ans_t, ans_theta);
        hit.r = color[0];
        hit.g = color[1];
        hit.b = color[2];


        hit.spec = spec;
    }

    return hit;
}

bool Bezier::Intersect(Ray ray)
{
    Hit hit = RayCast(ray);

    return hit.valid;
}

std::pair<Polynomial, Polynomial> Bezier::getP(int l, int n)
{
    if (n == 1)
        return std::pair<Polynomial, Polynomial>(controlPoints[l].x/scale, controlPoints[l].y/scale);
    std::pair<Polynomial, Polynomial> p1 = getP(l, n - 1), p2 = getP(l + 1, n - 1);
    return std::pair<Polynomial, Polynomial>(Polynomial(1, -1) * p1.first  + Polynomial(0, 1) * p2.first,
                                             Polynomial(1, -1) * p1.second + Polynomial(0, 1) * p2.second);
}

void Bezier::init()
{
    printf("initializing Bezier\n");

    std::pair<Polynomial, Polynomial> tmp = getP(0, controlPoints.size());
    px = tmp.first; py = tmp.second;
    dpx = px.derivative(); dpy = py.derivative();

    Dz.x = Dz.y = Dx.y = Dx.z = Dy.x = Dy.z = 0;
    Dz.z = Dx.x = Dy.y = 1;

    std::cout << "Bezier points:\n";
    for (float u = 0.0f, i = 0, du = 0.01; u <= 1.0f; u += du, i++) {
        for (float v = 0.0f, j = 0, dv = 0.01; v <= 1.0f; v += dv, j++) {
            boundingBox.include(getPoint(u, v * 2 * PI));
        }
    }

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

cv::Vec3b Bezier::getColor(double t, double theta)
{
    cv::Vec3b color;
    if (texture.data == NULL)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;

        return color;
    }
    double x = t, y = theta / PI / 2 + 0.5;

    return texture.getColor(y, x);
}