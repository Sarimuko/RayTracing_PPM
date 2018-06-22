//
// Created by wangyihan on 2018/5/20.
//

#ifndef RAYTRACING_FUNCTIONS_H
#define RAYTRACING_FUNCTIONS_H

#include <opencv2/opencv.hpp>
#include <math.h>
//#include "Ray.h"
#include "Hit.h"
#include "const.h"

const double PI = acos(-1);



static inline int sign(double x, double eps = CONST::EPS){return x < -eps ? -1 : (x > eps);}
static inline double sqr(double x) {return x * x;}
static inline double randreal(){ return (1.0 * rand() * (RAND_MAX + 1.) + rand()) / ((RAND_MAX + 1.) * (RAND_MAX + 1.) - 1); }

static double max(double a, double b)
{
    return a > b? a: b;
}

static double min(double a, double b)
{
    return a < b? a : b;
}
static cv::Point3d regu(cv::Point3d o)
{
    cv::Point3d res = o;
    res = res/(norm(o));

    //std::cout << "try to nomalization "<<o<<' '<<res<<std::endl;

    return res;
}

static cv::Vec3d regu(cv::Vec3d o)
{
    cv::Vec3d res = o;
    res = res/(norm(cv::Point3d(o)));

    //std::cout << "try to nomalization "<<o<<' '<<res<<std::endl;

    return res;
}

static cv::Point3d getReflect(cv::Point3d pd, cv::Point3d N)//得到反射光线
{
    cv::Point3d Rd;
    Rd = pd - 2 * (pd.ddot(N)) * N;
    Rd = Rd / (norm(cv::Vec3d(Rd)));//单位化

    return Rd;
}

static double Phong(Hit hit, cv::Vec3d v_, double s)//返回Blinn-Phong模型的光强
{
    cv::Vec3d l = regu(hit.Pd);
    cv::Vec3d v = regu(v_);
    cv::Vec3d n = regu(hit.N);
    cv::Vec3d r = regu(hit.Rd);

    double inten = hit.deffuseR  * abs(n.ddot(l)) + hit.spec * pow(std::max<double>(-r.ddot(v), 0), s);
    //std::cout << "pow" << l<< std::endl;

    return inten;

}

static double Blinn_Phong(Hit hit, cv::Vec3d v_, double s)//光线的hit信息（入射光线，反射光线），视线方向
{
    cv::Vec3d l = hit.Pd;
    cv::Vec3d v = v_;
    cv::Vec3d n = hit.N;
    cv::Vec3d r = hit.Rd;
    cv::Vec3d h = (v + l)/2;

    double inten = hit.deffuseR * CONST::rou + hit.deffuseR * pow(norm(n.t() * h)/norm((n.t() * l)), s);

    return inten;
}

static cv::Point3d getRefract(cv::Point3d origin, double n0, double n1, cv::Point3d N)
{
    origin = -origin;
    double cos1 = N.dot(origin), sin22 = (1 - cos1 * cos1) * (n0/n1) * (n0/n1);

    if (cos1 < 0)
    {
        N = -N;
    }
    //isRefracted = 0;
    if (sin22 > 1) return getReflect(-1 * origin, N);
    double cos2 = sqrt(1 - sin22);
    //isRefracted = 1;
    cv::Point3d tmp = -origin * (n0 / n1) - (cos2 - cos1 * n0 / n1) * N;
    return regu(tmp);

    /*double sin0 = cv::norm(origin.cross(N));
    double sin1 = sin0 * n0 / n1;

    cv::Point3d rd;

    if (sin1 > 0)
    {
        rd = getReflect(origin, N);
    }

    cv::Point3d z = origin.cross(N);
    cv::Point3d i = z.cross(N);
    cv::Point3d rN = regu(origin + i * sin0);





    rd = rN - i * sin1/(sqrt(1 - sin1 * sin1));
    rd = regu(rd);

    return rd;*/
}


static bool cmp0(Hit a, Hit b)
{
    return a.P.x < b.P.x;
}

static bool cmp1(Hit a, Hit b)
{
    return a.P.y < b.P.y;
}

static bool cmp2(Hit a, Hit b)
{
    return a.P.z < b.P.z;
}

static double dist(cv::Point3d a, cv::Point3d b)
{
    return cv::norm(a - b);
}

static cv::Point3d getTexture(int texture, int x, int y)
{
    cv::Point3d color;
    return color;
}




#endif //RAYTRACING_FUNCTIONS_H
