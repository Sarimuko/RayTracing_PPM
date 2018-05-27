//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_HIT_H
#define RAYTRACING_HIT_H

#include <opencv2/opencv.hpp>

struct Hit//储存相交点的信息
{
    cv::Point3d P;//相交点
    cv::Point3d N;//法向方向
    cv::Point3d Pd;//入射方向

    cv::Point3d Rd;//反射方向
    double RI;//反射光线强度

    double reflectCoefficience;//相交表面的反射系数
    double refractCoefficience;//相交表面的折射系数
    double deffuseR;//漫反射系数

    double t;//t of ray

    bool valid = false;

    double r, g, b;
};


#endif //RAYTRACING_HIT_H
