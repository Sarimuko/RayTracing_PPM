//
// Created by wangyihan on 2018/5/19.
//

#include "Camera.h"
#include "Functions.h"
#include "Scene.h"
#include "const.h"

cv::Mat Camera::CreatePhoto(Scene& scene)
{
    cv::Mat_<cv::Vec3b> photo(CONST::h, CONST::w, cv::Vec3b(0, 0, 0));
    cv::Point3f photoCenter = position + fD * direction;
    cv::Point3f zAxis(0, 0, 1);
    cv::Point3f xAxis(direction);
    cv::Point3f yAxis = zAxis.cross(xAxis);

    cv::Point3f leftDown = photoCenter - CONST::w / 2 * yAxis - CONST::h / 2 * zAxis;

    for (int iter = 0; iter < CONST::MAX_ITER;iter ++)
    {
        for (int i=0;i<CONST::h;i++)
        {
            for (int j=0;j<CONST::w;j++)
            {
                Ray ray = ProduceRay(leftDown + i * zAxis + j * yAxis);
                cv::Vec3b color = RayTracing(ray, scene, 1);

                photo(CONST::h - 1 - i, CONST::w - 1 - j) += color;
            }
        }
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

cv::Vec3b Camera::RayTracing(Ray& ray, Scene& scene, double coefficient)
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
            inten += Phong(LightHits[i], hit.Pd, CONST::s);
        }
    } else
    {
        inten = hit.deffuseR;
    }


#ifdef DEBUG
    std::cout << inten << std::endl;
    std::cout << "coefficience: "<<coefficient<<std::endl;
#endif

    color[2] += coefficient * hit.r * inten;
    color[1] += coefficient * hit.g * inten;
    color[0] += coefficient * hit.b * inten;

    double coeff_2 = coefficient * hit.reflectCoefficience;//只考虑反射
    if (coeff_2 > 0.1)
    {
        Ray rray(hit.P, hit.Rd);
#ifdef DEBUG
        std::cout << "rray: "<<hit.P << ' '<<hit.Rd<<std::endl;
#endif
        color += RayTracing(rray, scene, coeff_2);
    }

    return color;
}