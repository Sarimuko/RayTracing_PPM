//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_HIT_H
#define RAYTRACING_HIT_H

#include <opencv2/opencv.hpp>

struct Hit//储存相交点的信息
{
    int px, py;

    int cnt = 0;
    int ncnt = 0;//一轮迭代之后新增的个数


    cv::Point3d P;//相交点
    cv::Point3d N;//法向方向
    cv::Point3d Pd;//入射方向

    cv::Point3d Rd;//反射方向
    double RI;//贡献权重

    double radius = 1;//光子半径

    double reflectCoefficience;//相交表面的反射系数
    double refractCoefficience;//相交表面的折射系数
    double deffuseR;//漫反射系数
    double spec;

    double n0, n1;//击中交界面两侧的折射率

    double t;//t of ray

    bool valid = false;

    double r, g, b;

    cv::Vec3d color;//累积的颜色
    //cv::Vec3d ncolor;//一轮迭代的颜色
};


#endif //RAYTRACING_HIT_H
