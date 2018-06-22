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
    ray.rayType = 2;//light

    return ray;
}



Ray Light::randomRay()
{
    Ray ray;
    ray.p0 = position;


    double x, y, z;
    do {
        x = 2. * randreal() - 1;
        y = 2. * randreal() - 1;
        z = 2. * randreal() - 1;
    } while (x*x+y*y+z*z>1 || x*x+y*y+z*z < CONST::EPS);
    //return Vector3(x, y, z).normalized();

    ray.pd.x = x;
    ray.pd.y = y;
    ray.pd.z = z;

    ray.intensity = intensity;

    ray.pd = regu(ray.pd);


    ray.intensity = intensity;

    ray.rayType = 2;//光子光线

    return ray;
}