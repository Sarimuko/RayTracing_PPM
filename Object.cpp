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
        if (sign(d2 - radius * radius) >= 0)
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
    result.N = regu(result.N);//单位化

    result.Rd = getReflect(ray.pd, result.N);

    result.r = r;
    result.g = g;
    result.b = b;

    if(inBall)
    {
        result.n0 = n;
        result.n1 = 1;
    } else
    {
        result.n0 = 1;
        result.n1 = n;
    }
    result.reflectCoefficience = reflectR;
    result.refractCoefficience = refractR;
    result.deffuseR = rou_d;
    result.spec = spec;

    //std::cout << "ball intersect: "<<ray.p0 << ' '<<ray.pd<<' '<<result.P<<std::endl;

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

cv::Vec3b Ball::getColor(cv::Point3d _P)
{
    cv::Vec3b color;

    cv::Point3d P = _P - centre;

    if (texture.data == NULL)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;

        return color;
    }

    double x, y;
    if (!sign(P.x) && !sign(P.y)) x = 0, y = 0;
    else x = atan2(P.y, P.x)/2/PI + 0.5, y = asin(P.z) / PI + 0.5;

    return texture.getColor(x, y);
    //cv::Point3d PP = P - centre;
}

Hit Plane::RayCast(Ray ray)
{
    Hit result;
    double t = - (D + N.ddot(ray.p0))/N.ddot(ray.pd);
    if (t < 0)
    {
        result.valid = false;
        return result;
    }

    //std::cout << "t: "<<t <<std::endl;

    result.valid = true;
    result.t = t;
    result.P = ray.p0 + t * ray.pd;
    result.N = regu(N);
    result.Pd = ray.pd;
    result.Rd = getReflect(result.Pd, result.N);

    result.spec = spec;
    //result.Rd = -result.Rd;

    result.deffuseR = rou_d;
    result.reflectCoefficience = reflectR;
    result.refractCoefficience = refractR;

    result.r = r;
    result.g = g;
    result.b = b;

    return result;
}

bool Plane::Intersect(Ray ray)
{
    double t = - (D + N.ddot(ray.p0))/N.ddot(ray.pd);
    if (t < 0)
    {
        return false;
    }
    return true;
}

cv::Vec3b Plane::getColor(cv::Point3d P)
{
    cv::Vec3b color;
    if (texture.data == NULL)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;

        return color;
    }
    P.x -= ox;
    P.y -= oy;
    P.z = (- D - N.x * P.x - N.y * P.y) / N.z;


    double x = abs(P.x) / len_x, y = abs(P.y)/len_y;

    while (x > 1)
        x -= 1;
    while (y > 1)
        y -= 1;

    return texture.getColor(x, y);
}