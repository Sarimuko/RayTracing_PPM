//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include <opencv2/opencv.hpp>
#include "Hit.h"
#include "Ray.h"
#include "Texture.h"


class Object {//物体基类
    friend class Scene;

public:
    cv::Point3d origin;//模型原点位置
    int id;//物体id

    Texture texture;

    bool isBackground = false;

    double rou_d = 0;//diffusion

    //bool  transparent = false;
    double n = 1.5;//光线的 折射率
    double refractR = 0;//refraction rate折射率
    double reflectR = 1.0;//反射率
    double spec = 0;

    cv::Vec3d color;

    //int texture = 0;//id of texture



    double r = 23, g = 123, b = 17;//物体固有颜色

    Object()
    {
        id = -1;
    }
    virtual Hit RayCast(Ray ray) = 0;
    virtual bool Intersect(Ray ray) = 0;
    virtual cv::Vec3b getColor(cv::Point3d P) = 0;//获得颜色

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
    cv::Vec3b getColor(cv::Point3d P);
};

class Plane: public Object
{
private:
    cv::Point3d N;
    double D;//ax + by + cz + d = 0;

    double ox, oy;//原点

    double len_x, len_y;

public:
    Plane(double a, double b, double c, double d){N.x = a;N.y = b;N.z = c; ox = oy = 0.0; len_x = len_y = abs(D); D = d;isBackground = true; N = regu(N); reflectR = 0; rou_d = 0.3; spec = 0.3;}
    Hit RayCast(Ray ray);
    bool Intersect(Ray ray);
    cv::Vec3b getColor(cv::Point3d P);

};


#endif //RAYTRACING_OBJECT_H
