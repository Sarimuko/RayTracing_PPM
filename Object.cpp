//
// Created by wangyihan on 2018/5/19.
//

#include "Object.h"
#include "Functions.h"

Hit Ball::RayCast(Ray ray)
{
    Hit result;

    bool inBall = false;
    bool intersect = false;
    bool approach = false;

    double d2;

    cv::Vec3d l = centre - ray.p0;
    if (norm(l) < radius)
        inBall = true;

    double tp = ray.pd.ddot((cv::Point3d)l);
    if (tp < 0)
    {
        intersect = false;
        return result;
    }
    else
    {
        d2 = (norm(l)) * (norm(l)) - tp * tp;
        if (d2 > radius * radius)
        {
            intersect = false;
            return result;
        }
    }

    double tprime = sqrt(radius * radius - d2);
    double t;
    if (inBall)
    {
        t = tp + tprime;
    }
    else
    {
        t = tp - tprime;
    }

    //cv::Point3f NP = ray.p0 + t * ray.pd;
    result.valid = true;

    result.t = t;

    result.P = ray.p0 + t * ray.pd;
    result.Pd = ray.pd;
    result.N = result.P - centre;
    result.N = result.N / (norm(cv::Vec3d(result.N)));//单位化

    result.Rd = getReflect(ray.pd, result.N);

    result.r = r;
    result.g = g;
    result.b = b;

    result.reflectCoefficience = reflectR;
    result.refractCoefficience = refractR;

    return result;




}

bool Ball::Intersect(Ray ray)
{
    Hit result;

    bool inBall = false;
    bool intersect = false;
    bool approach = false;

    double d2;

    cv::Vec3d l = centre - ray.p0;
    if (norm(l) < radius)
        inBall = true;

    double tp = ray.pd.ddot((cv::Point3f)l);
    if (tp < 0)
    {
        intersect = false;
        return false;
    }
    else
    {
        d2 = (norm(l)) * (norm(l)) - tp * tp;
        if (d2 > radius * radius)
        {
            intersect = false;
            return false;
        }
    }

    return true;
}