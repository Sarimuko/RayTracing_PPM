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
    cv::Mat_<cv::Vec3b> rtphoto(CONST::h, CONST::w, cv::Vec3b(0, 0, 0));

    cv::Point3d photoCenter = position + fD * direction;

    cv::Point3d up(0, 0, 1);

    Dx = regu(direction);
    Dy = Dx.cross(up);
    Dz = Dx.cross(Dy);

    cv::Point3d leftDown = photoCenter - CONST::w / 2 * Dy * yscale - CONST::h / 2 * Dz * xscale;

        for (int i=0;i<CONST::h;i++)
        {
            for (int j=0;j<CONST::w;j++)
            {
                Ray ray = ProduceRay(leftDown + i * Dz * yscale + j * Dy * xscale);
                ray.rayType = 1;//视线光线

                if (applyDepth)
                {
                    for (int k=0;k < sample ;k ++)
                        scene.RayTracing(ray, 1.0, 0, i, j);
                }
                else
                    scene.RayTracing(ray, 1, 0, i, j);
            }
            std::cout << "finished: "<<i<<std::endl;
        }
    //scene.tree.create(scene.hits);

    for (int iter = 0;iter < 1000; iter ++)
    {
        scene.shootPhoton(CONST::PHOTON_PER_ITER);
        cv::Mat3d tmp(photo.rows, photo.cols, cv::Vec3d(0, 0, 0));



        int hitsize = scene.hits.size();
        for (int i=0;i < hitsize;i++)
        {
            tmp(scene.hits[i].px, scene.hits[i].py) = tmp(scene.hits[i].px, scene.hits[i].py) + scene.hits[i].RI * (cv::Vec3d)(scene.hits[i].color)/CONST::pi/(scene.hits[i].radius * scene.hits[i].radius)/scene.Ntotal * 3000000;//10000000;//2000000
        }

        photo = min(tmp/sample, 255);

            cv::imwrite("/Users/wangyihan/Desktop/ComputerGraphics__.png",photo);
            std:: cout << iter<<std::endl;


    }
    return photo;
}

/*cv::Mat Camera::CreatePhotoPT(Scene &scene)
{
    cv::Mat_<cv::Vec3b> photo(CONST::h, CONST::w, cv::Vec3b(0, 0, 0));
    cv::Point3f photoCenter = position + fD * direction;
    cv::Point3f zAxis(0, 0, 1);
    cv::Point3f xAxis(direction);
    cv::Point3f yAxis = zAxis.cross(xAxis);
    yAxis = regu(yAxis);

    cv::Point3f leftDown = photoCenter - CONST::w / 2 * yAxis * yscale - CONST::h / 2 * zAxis * xscale;

    for (int i=0;i<CONST::h;i++)
    {
        for (int j=0;j<CONST::w;j++)
        {
            Ray ray = ProduceRay(leftDown + i * zAxis * xscale + j * yAxis * yscale);
            ray.rayType = 1;//视线光线

            cv::Vec3b color = scene.RayTracing(ray, 1, 0, i, j);

            photo(CONST::h - 1 - i, CONST::w - 1 - j) += color;
        }
        std::cout << "finished: "<<i<<std::endl;
    }
    //scene.tree.create(scene.hits);


    return photo;
}*/

Ray Camera::ProduceRay(cv::Point3d p)
{
    if (!applyDepth)
    {
        Ray ray;
        ray.p0 = position;
        ray.pd = p - position;
        ray.pd = regu(ray.pd);

        ray.intensity = 1;
        ray.rayType = 1;//cameraRay

        return ray;
    }
    else
    {
        Ray ray;
        double theta = rand() / (double)RAND_MAX * 2 * CONST::pi;

        ray.p0 = position;
        ray.p0 += radius * sin(theta) * Dy;
        ray.p0 += radius * cos(theta) * Dz;

        cv::Point3d hitpoint;
        cv::Point3d photoCenter = position + fD * Dx;

        hitpoint = position + Dx * focusD + focusD / fD * (p - photoCenter);
        ray.pd = regu(hitpoint - ray.p0);

        ray.intensity = 1.0;
        ray.rayType = 1;

        return ray;

    }
}


