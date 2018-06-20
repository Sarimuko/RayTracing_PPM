//
// Created by wangyihan on 2018/5/20.
//

#include "Light.h"
#include "Functions.h"
#include "const.h"

Ray Light::getRay(cv::Point3d p)
{
    Ray ray;
    ray.p0 = position;
    ray.pd = p - ray.p0;

    ray.pd = regu(ray.pd);

    ray.intensity = intensity;
    ray.rayType = 1;//light

    return ray;
}



Ray Light::randomRay()
{
    double phi = rand()/(double)RAND_MAX * 2 * CONST::pi;
    double theta = rand()/(double)RAND_MAX * CONST::pi;

    Ray ray;
    ray.p0 = position;
    ray.pd.x = sin(theta) * cos(phi);
    ray.pd.y = sin(theta) * sin(phi);
    ray.pd.z = cos(theta);

    ray.intensity = intensity;

    ray.rayType = 2;//光子光线
}