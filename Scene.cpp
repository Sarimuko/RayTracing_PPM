//
// Created by wangyihan on 2018/5/19.
//

#include "Scene.h"
#include <limits.h>

bool Scene::intersect(Ray ray)
{
    int size = objectList.size();
    for (int i=0;i<size;i++)
    {
        if (objectList[i]->Intersect(ray) && !objectList[i] -> isBackground)
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
        //std::cout << "s: " << s.pd<<std::endl;
        if (!intersect(rs))
        {
            Hit result;
            result.P = P;
            result.Pd = s.pd;
            result.N = N;
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