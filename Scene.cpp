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

            result.RI = lights[i]->intensity;
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


cv::Vec3b Scene::RayTracing(Ray& ray, double coefficient, int iter, int x, int y)
{
    cv::Vec3b color(0, 0, 0);
    Hit hit = firstIntersect(ray);


    if (ray.rayType == 1)//如果是视线光线交点，那么加入到视线交点列表中
    {
        hit.RI = coefficient;//加上权重信息
        hit.px = x;
        hit.py = y;

        addHit(hit);

        double reflectf = coefficient * hit.reflectCoefficience;//只考虑反射
        double refractf = coefficient * hit.refractCoefficience;//折射
        if (iter < CONST::MAX_ITER && reflectf > 0.00001)
        {
            Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
            RayTracing(rray, reflectf, iter + 1, x, y);
        }

        if (iter < CONST::MAX_ITER && refractf > 0.00001 )
        {
            cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
            Ray refraR(hit.P + refraD * 0.0001, refraD);

            RayTracing(refraR, refractf, iter + 1, x, y);
        }

    }//如果是视线光线，加入场景的hits列表，并递归追踪
    else if (ray.rayType == 2)//如果是光子光线
    {
        double rate = rand() / (double)RAND_MAX;
        if (rate < hit.deffuseR)
        {
            //留下来找邻近的Hit
            int hitsize = hits.size();
            for (int i=0;i<hitsize;i++)
            {
                if (dist(hits[i].P, hit.P) < hits[i].radius)
                {
                    hits[i].cnt++;//增加一个计数

                    cv::Vec3b color(0, 0, 0);
                    double inten = 0.0;
                    inten += Phong(hit, hits[i].Pd, CONST::s);

                    color[2] += hits[i].r * inten;
                    color[1] += hits[i].g * inten;
                    color[0] += hits[i].b * inten;

                    hits[i].color += (cv::Point3d)color;

                }
            }
        }
        else if (rate - hit.deffuseR < hit.reflectCoefficience)
        {
            Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
            //color += RayTracing(rray, reflectf, iter + 1, x, y);
            RayTracing(rray, 1, iter + 1, x, y);
        }
        else if (rate - hit.deffuseR - hit.reflectCoefficience < hit.refractCoefficience)
        {
            //折射
            cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
            Ray refraR(hit.P + refraD * 0.0001, refraD);
            
            RayTracing(refraR, 1, iter + 1, x, y);
        }
        //否则吸收。。？
    }

    return color;
}