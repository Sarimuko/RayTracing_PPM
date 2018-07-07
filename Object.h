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
    double n = 1.6;//光线的 折射率
    double refractR = 0;//refraction rate折射率
    double reflectR = 1.0;//反射率
    double spec = 0;

    double r = 23, g = 123, b = 17;//物体固有颜色

    Object()
    {
        id = -1;
    }

    void loadTexture(std::string filename)
    {
        cv::Mat image = cv::imread(filename, 1);
        //std::cout << image<<std::endl;
        texture = image;
    }

    virtual Hit RayCast(Ray ray) = 0;
    virtual bool Intersect(Ray ray) = 0;
    virtual cv::Vec3b getColor(cv::Point3d P){return cv::Vec3b(0, 0, 0);};//获得颜色

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
public:
    bool hasBorder = false;

    cv::Point3d N;
    double D;//ax + by + cz + d = 0;

    cv::Point3d O;//原点
    cv::Point3d Dx, Dy;


    double len_x, len_y;

public:
    Plane(double a, double b, double c, double d){N.x = a;N.y = b;N.z = c; O.x = O.y = O.z = 0.0; len_x = len_y = 10; D = d;isBackground = true; N = regu(N); reflectR = 0; rou_d = 0.3; spec = 0.3;}
    Plane(cv::Point3d _O, cv::Point3d _Dx, cv::Point3d _Dy):O(_O), Dx(_Dx), Dy(_Dy)
    {
        N = _Dx.cross(_Dy);

        N = regu(N);
        len_x = len_y = 10;

        D = -1 * (N.ddot(O));

        reflectR = 0; rou_d = 0.2; spec = 0.4;

    }
    Hit RayCast(Ray ray);
    bool Intersect(Ray ray);
    cv::Vec3b getColor(cv::Point3d P);
};


#endif //RAYTRACING_OBJECT_H
