//
// Created by wangyihan on 2018/5/19.
//

#include "Scene.h"
#include "const.h"
#include <limits.h>
//#include <omp.h>

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

void Scene::shootPhoton(int num)
{

    for (auto light: lights)
    {
        for (int i=0;i < num;i++)
        {
            if (i % 10000 == 0)
                std::cout << i<<std::endl;
            Ray ray = (*light).randomRay();
            Ntotal ++;
            //std::cout << ray.rayType<<std::endl;
            RayTracing(ray, 1, 0, 0, 0);


        }
    }
    processPhotons();

}


cv::Vec3b Scene::RayTracing(Ray& ray, double coefficient, int iter, int x, int y)
{
    cv::Vec3b color(0, 0, 0);
    Hit hit = firstIntersect(ray);


    if (ray.rayType == 1)//如果是视线光线交点，那么加入到视线交点列表中
    {
        double inten = 0.0;

        //std::vector<Hit> LightHits = getLightRay(hit.P, hit.N);

        hit.RI = coefficient;//加上权重信息
        hit.px = x;
        hit.py = y;

        //std::cout << hit.P<<hit.RI << std::endl;

        addHit(hit);

        double reflectf = coefficient * hit.reflectCoefficience;//只考虑反射
        double refractf = coefficient * hit.refractCoefficience;//折射

        if (iter < CONST::MAX_ITER && reflectf > 0.00001)
        {
            Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
            rray.rayType = 1;
            RayTracing(rray, reflectf, iter + 1, x, y);
        }

        if (iter < CONST::MAX_ITER && refractf > 0.00001 )
        {
            cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
            Ray refraR(hit.P + refraD * 0.0001, refraD);
            refraR.rayType = 1;

            RayTracing(refraR, refractf, iter + 1, x, y);
        }

    }//如果是视线光线，加入场景的hits列表，并递归追踪
    else if (ray.rayType == 2)//如果是光子光线
    {
            //int hitsize = hits.size();
            hit.RI = ray.intensity;

            double rate = rand() / (double)RAND_MAX;
            if (rate < hit.deffuseR)
            {
                //if (iter > 0)//只存间接光照
                photonHits.push_back(hit);
            }
            else if (rate - hit.deffuseR < hit.reflectCoefficience && iter < CONST::MAX_ITER)
            {
                Ray rray(hit.P + hit.Rd * 0.0001, hit.Rd);
                rray.rayType = 2;
                RayTracing(rray, 1, iter + 1, x, y);
            }
            else if (rate - hit.deffuseR - hit.reflectCoefficience < hit.refractCoefficience && iter < CONST::MAX_ITER)
            {
                cv::Point3d refraD = getRefract(hit.Pd, hit.n0, hit.n1, hit.N);
                Ray refraR(hit.P + refraD * 0.0001, refraD);
                refraR.rayType = 2;

                RayTracing(refraR, 1, iter + 1, x, y);
            }

    }

    return color;
}

void Scene::updateHit()
{
    int hitsize = hits.size();
    for (int i=0; i < hitsize; i ++)
    {
        double rate = (hits[i].cnt + CONST::a * hits[i].ncnt)/(hits[i].cnt + hits[i].ncnt);//改变半径的系数

        hits[i].radius = hits[i].radius * sqrt(rate);
        //hits[i].color = hits[i].color + rate * hits[i].ncolor;
        //hits[i].ncolor[0] = hits[i].ncolor[1] = hits[i].ncolor[2] = 0;

        hits[i].cnt = hits[i].cnt + (int)(CONST::a * hits[i].ncnt);
        hits[i].ncnt = 0;
    }
}

void Scene::processPhotons()
{
    tree.create(photonHits);

    int size = hits.size();
    for (int i=0;i< size;i++)
    {

        if (i % 10000 == 0)
        {
            std::cout << i<<std::endl;
        }
        std::vector<Hit> photons = tree.findRange(hits[i], hits[i].radius);
        int photonNum = photons.size();

        cv::Vec3d color(0, 0, 0);

        for (int j=0;j< photonNum;j++)
        {

            double inten = 0.0;
            inten += photons[j].RI;
            //std::cout << "photon inten: "<<inten<<std::endl;

            color[2] += (double)hits[i].r * inten;
            color[1] += (double)hits[i].g * inten;
            color[0] += (double)hits[i].b * inten;

        }

        //std::cout << color<<std::endl;

        if (photonNum > 0)
        {
            if (hits[i].cnt == 0)
            {
                hits[i].cnt = photonNum;
                hits[i].color = color;
            }
            else
            {
                double rate = (hits[i].cnt + CONST::a * photonNum)/(hits[i].cnt + photonNum);//改变半径的系数
                hits[i].radius = hits[i].radius * sqrt(rate);
                //std::cout << hits[i].radius<<std::endl;

                hits[i].color = (hits[i].color + color) * rate;


                hits[i].cnt = hits[i].cnt + (int)(CONST::a * photonNum);
            }

        }




    }

    photonHits.clear();
}