//
// Created by wangyihan on 2018/5/20.
//

#include "Light.h"
#include "Functions.h"

Ray Light::getRay(cv::Point3d p)
{
    Ray ray;
    ray.p0 = position;
    ray.pd = p - ray.p0;

    ray.pd = regu(ray.pd);

    ray.intensity = intensity;
    ray.rayType = 1;//light
}