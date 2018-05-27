//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include <opencv2/opencv.hpp>
#include "Hit.h"
#include "Ray.h"


class Object {//物体基类
    friend class Scene;
protected:
    cv::Point3f orgin;//模型原点位置
    int id;//物体id

    double rou_d;//diffusion

    bool  transparent = false;
    double refractR;//refraction rate折射率
    double reflectR;//反射率

    double r, g, b;//物体固有颜色

public:
    Object()
    {
        id = -1;
    }
    virtual Hit RayCast(Ray ray) = 0;
    virtual bool Intersect(Ray ray) = 0;

    virtual void Translate(cv::Point3f direction){}//平移
    virtual void RotateX(cv::Point3f c, double theta){}
    virtual void RotateY(cv::Point3f c, double theta){}
    virtual void RotateZ(cv::Point3f c, double theta){}

    virtual void Rotate(cv::Point3f c, cv::Point3f axis, double theta){}//旋转
};

class Ball: public Object
{
private:
    cv::Point3d centre;
    double radius;
public:
    Ball(double c_x, double c_y, double c_z, double radius, int id)
    {
        centre.x = c_x;
        centre.y = c_y;
        centre.z = c_z;

        this -> radius = radius;
        this -> id = id;

    }
    Hit RayCast(Ray ray);
    bool Intersect(Ray ray);
};


#endif //RAYTRACING_OBJECT_H
