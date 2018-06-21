//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H

#include <vector>
#include "Object.h"
#include "Light.h"
#include "Kd_tree.h"


class Scene {

    friend class Camera;
private:
    std::vector<Object*> objectList;//物体列表
    std::vector<Light*> lights;//光源列表

    std::vector<Hit> hits;//目光击中点列表，现在就直接枚举好了
    std::vector<Hit> photonHits;//光子击中的信息列表

    int Ntotal = 0;//发射的总光子数

    Kd_tree tree;

public:
    void addObject(Object* object){objectList.push_back(object);}//加入一个物体
    void addHit(Hit hit){hits.push_back(hit);  Ntotal += 1;}
    Object* getObject(int id);//获得一个id为id的物体，如果找不到，返回NULL
    void shootPhoton(int num, Light light);//发射光子

    cv::Vec3b RayTracing(Ray& ray, double coefficient, int iter, int x, int y);

    void addLight(Light* light){lights.push_back(light);}
    Light* getLight(int id);//获得id为id的光源

    bool intersect(Ray ray);//某条光线和场景中的物体是否有相交
    Hit firstIntersect(Ray ray);//返回第一个交点的信息

    std::vector<Hit> getLightRay(cv::Point3d P, cv::Point3d N);//得到和光线的交点信息
    void updateHit();

    void processPhotons();
};


#endif //RAYTRACING_SCENE_H
