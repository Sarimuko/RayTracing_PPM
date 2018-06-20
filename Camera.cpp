//
// Created by wangyihan on 2018/5/19.
//

#include "Camera.h"
#include "Functions.h"
#include "Scene.h"
#include "const.h"
#include <math.h>

cv::Mat Camera::CreatePhoto(Scene& scene)
{
    cv::Mat_<cv::Vec3b> photo(CONST::h, CONST::w, cv::Vec3b(0, 0, 0));
    cv::Point3f photoCenter = position + fD * direction;
    cv::Point3f zAxis(0, 0, 1);
    cv::Point3f xAxis(direction);
    cv::Point3f yAxis = zAxis.cross(xAxis);
    yAxis = regu(yAxis);

    cv::Point3f leftDown = photoCenter - CONST::w / 2 * yAxis - CONST::h / 2 * zAxis;

        for (int i=0;i<CONST::h;i++)
        {
            for (int j=0;j<CONST::w;j++)
            {
                Ray ray = ProduceRay(leftDown + i * zAxis + j * yAxis);
                ray.rayType = 1;//视线光线

                cv::Vec3b color = scene.RayTracing(ray, 1, 0, i, j);

                //photo(CONST::h - 1 - i, CONST::w - 1 - j) += color;
            }
            std::cout << "finished: "<<i<<std::endl;
        }


    return photo;
}

Ray Camera::ProduceRay(cv::Point3d p)
{
    Ray ray;
    ray.p0 = position;
    ray.pd = p - position;
    ray.pd = regu(ray.pd);

    ray.intensity = 1;
    ray.rayType = 0;//cameraRay

    return ray;

}

