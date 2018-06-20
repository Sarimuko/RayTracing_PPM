//
// Created by wangyihan on 2018/5/19.
//

#include "Scene.h"
#include "const.h"
#include <limits.h>

bool Scene::intersect(Ray ray)
{
    int size = objectList.size();
    for (int i=0;i<size;i++)
    {
        if (objectList[i]->Intersect(ray))
            return true;
    }
    return false;
}

Hit Scene::firstIntersect(Ray ray)
{
    std::vector<Hit> hits;//检测到的所有hit信息
    int size = objectList.size();

    for (int i=0;i<size;i++)
    {
        Hit hit;
        hit = objectList[i] -> RayCast(ray);
        if (hit.valid)
        {
            hits.push_back(hit);
        }
    }

    //std::cout << "size of hits: "<<hits.size()<<std::endl;

    int hitSize = hits.size();
    double min_t = hits[0].t;
    Hit min_Hit = hits[0];

    for (int i=0;i<hitSize;i++)
    {
        if (min_t > hits[i].t)
        {
            min_t = hits[i].t;
            min_Hit = hits[i];
        }
    }

    //std::cout << "min t: "<<min_t<<std::endl;


    //根据物体属性和计算击中点的其他信息


    return min_Hit;
}

std::vector<Hit> Scene::getLightRay(cv::Point3d P, cv::Point3d N)
{
    //std::cout << "getLightRay"<<std::endl;
    std::vector<Hit> ans;
    int size = lights.size();
    for (int i=0;i<size;i++)
    {
        Ray s(lights[i] -> position, P - lights[i] -> position);
        Ray rs(P, lights[i] -> position - P);
        rs.p0 = rs.p0 + rs.pd * 0.00001;
        //std::cout << "s: " << s.pd<<std::endl;
        Hit min_hit = firstIntersect(rs);
        if (min_hit.t != 0 &&  min_hit.t > cv::norm(lights[i] -> position - P))
        {
            Hit result;
            result.P = P;
            result.Pd = s.pd;
            result.N = regu(N);
            result.Rd = getReflect(result.Pd, result.N);
            //result.Rd = -result.Rd;


            result.RI = lights[i]->intensity;

            //std::cout << "get light ray debug: "<< result.Rd << ' '<< result.Pd<<std::endl;

            result.valid = true;

            ans.push_back(result);

        }
    }
    return ans;
}

Light* Scene::getLight(int id)
{
    for (int i=0;i<lights.size();i++)
    {
        if (lights[i] -> id == id)
            return lights[i];
    }
}

Object* Scene::getObject(int id)
{
    for (int i=0;i<objectList.size();i++)
    {
        if (objectList[i] -> id == id)
            return objectList[i];
    }
}

void Scene::shootPhoton(int num, Light light)
{
    for (int i=0;i < num;i++)
    {
        Ray ray = light.randomRay();

    }

}


cv::Vec3b Scene::RayTracing(Ray& ray, double coefficient, int iter)
{
    cv::Vec3b color(0, 0, 0);
    //std::cout << "Ray Tracing"<<std::endl;
    Hit hit = firstIntersect(ray);
    //std::cout << "Ray Tracing"<<std::endl;

    double inten = 0.0;

    std::vector<Hit> LightHits = getLightRay(hit.P, hit.N);
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
    addHit(hit);//加入场景的hits列表

    double reflectf = coefficient * hit.reflectCoefficience;//只考虑反射
    double refractf = coefficient * hit.refractCoefficience;//折射
    if (iter < CONST::MAX_ITER && reflectf > 0.00001)
    {
        Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
#ifdef DEBUG
        std::cout << "rray: "<<hit.P << ' '<<hit.Rd<<std::endl;
#endif
        color += RayTracing(rray, reflectf, iter + 1);
    }

    if (iter < CONST::MAX_ITER && refractf > 0.00001 )
    {
        //Ray rray(hit.P, hit.Rd);
        cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
        Ray refraR(hit.P + refraD * 0.0001, refraD);
#ifdef DEBUG
        std::cout << "rray: "<<hit.P << ' '<<hit.Rd<<std::endl;
#endif
        color += RayTracing(refraR, refractf, iter + 1);
    }

    return color;
}