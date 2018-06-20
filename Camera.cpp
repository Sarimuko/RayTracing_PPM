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
                cv::Vec3b color = scene.RayTracing(ray, 1, 0);

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

/*cv::Vec3b Camera::RayTracing(Ray& ray, Scene& scene, double coefficient, int iter)
{
    cv::Vec3b color(0, 0, 0);
    //std::cout << "Ray Tracing"<<std::endl;
    Hit hit = scene.firstIntersect(ray);
    //std::cout << "Ray Tracing"<<std::endl;

    double inten = 0.0;

    std::vector<Hit> LightHits = scene.getLightRay(hit.P, hit.N);
    //std::cout << "size of lightHits: "<< LightHits.size()<<std::endl;

    if (!LightHits.empty())
    {
        for (int i=0;i<LightHits.size();i++)
        {
            LightHits[i].deffuseR = hit.deffuseR;
            LightHits[i].reflectCoefficience = hit.reflectCoefficience;
            LightHits[i].refractCoefficience = hit.refractCoefficience;
            inten += Phong(LightHits[i], ray.pd, CONST::s);
        }
    } else
    {
        inten = 0;//hit.deffuseR;
    }


#ifdef DEBUG
    std::cout << inten << std::endl;
    std::cout << "coefficience: "<<coefficient<<std::endl;
#endif

    color[2] += coefficient * hit.r * inten;
    color[1] += coefficient * hit.g * inten;
    color[0] += coefficient * hit.b * inten;

    hit.RI = coefficient;//加上权重信息
    scene.addHit(hit);//加入场景的hits列表

    double reflectf = coefficient * hit.reflectCoefficience;//只考虑反射
    double refractf = coefficient * hit.refractCoefficience;//折射
    if (iter < CONST::MAX_ITER && reflectf > 0.00001)
    {
        Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
#ifdef DEBUG
        std::cout << "rray: "<<hit.P << ' '<<hit.Rd<<std::endl;
#endif
        color += RayTracing(rray, scene, reflectf, iter + 1);
    }

    if (iter < CONST::MAX_ITER && refractf > 0.00001 )
    {
        //Ray rray(hit.P, hit.Rd);
        cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
        Ray refraR(hit.P + refraD * 0.0001, refraD);
#ifdef DEBUG
        std::cout << "rray: "<<hit.P << ' '<<hit.Rd<<std::endl;
#endif
        color += RayTracing(refraR, scene, refractf, iter + 1);
    }

    return color;
}*/

