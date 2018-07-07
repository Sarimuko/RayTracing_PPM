//
// Created by wangyihan on 2018/5/19.
//

#include "Object.h"
#include "Functions.h"

Hit Ball::RayCast(Ray ray)
{
    Hit result;

    bool inBall = false;

    double d2;

    cv::Vec3d l = centre - ray.p0;
    if (norm(l) < radius)
        inBall = true;

    double tp = ray.pd.ddot((cv::Point3d)l);
    if (tp < 0)
    {
        return result;
    }
    else
    {
        d2 = (norm(l)) * (norm(l)) - tp * tp;
        if (sign(d2 - radius * radius) >= 0)
        {
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

    return result;




}

bool Ball::Intersect(Ray ray)
{
    Hit result;

    double d2;

    cv::Vec3d l = centre - ray.p0;

    double tp = ray.pd.ddot((cv::Point3d)l);
    if (tp < 0)
    {
        return false;
    }
    else
    {
        d2 = (norm(l)) * (norm(l)) - tp * tp;
        if (d2 > radius * radius)
        {
            return false;
        }
    }

    return true;
}

cv::Vec3b Ball::getColor(cv::Point3d _P)
{
    cv::Vec3b color;

    cv::Point3d P = (_P - centre)/radius;

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

    cv::Point3d hitPoint = ray.p0 + t * ray.pd - O;
    if (hasBorder && (hitPoint.ddot(Dx) <= 0 || hitPoint.ddot(Dx) > len_x || hitPoint.ddot(Dy) <= 0 || hitPoint.ddot(Dy) > len_y))
    {
        result.valid = false;
        return result;
    }

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

    cv::Vec3b color = getColor(result.P);

    result.r = color[0];
    result.g = color[1];
    result.b = color[2];

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

    P -= O;

    double x = abs(P.ddot(Dx)) / len_x, y = abs(P.ddot(Dy))/len_y;

    while (x > 1)
        x -= 1;
    while (y > 1)
        y -= 1;

    return texture.getColor(x, y);
}