//
// Created by wangyihan on 2018/5/20.
//

#ifndef RAYTRACING_FUNCTIONS_H
#define RAYTRACING_FUNCTIONS_H

#include <opencv2/opencv.hpp>
#include <math.h>
#include "Hit.h"

static cv::Point3d regu(cv::Point3d o)
{
    cv::Point3d res = o;
    res = res/(norm(o));

    //std::cout << "try to nomalization "<<o<<' '<<res<<std::endl;

    return res;
}

static cv::Vec3d regu(cv::Vec3d o)
{
    cv::Vec3d res = o;
    res = res/(norm(cv::Point3d(o)));

    //std::cout << "try to nomalization "<<o<<' '<<res<<std::endl;

    return res;
}

static cv::Point3d getReflect(cv::Point3d pd, cv::Point3d N)//得到反射光线
{
    cv::Point3d Rd;
    Rd = pd - 2 * (pd.ddot(N)) * N;
    Rd = Rd / (norm(cv::Vec3d(Rd)));//单位化

    return Rd;
}

static double Phong(Hit hit, cv::Vec3d v_, double s)//返回Blinn-Phong模型的光强
{
    cv::Vec3d l = regu(hit.Pd);
    cv::Vec3d v = regu(v_);
    cv::Vec3d n = regu(hit.N);
    cv::Vec3d r = regu(hit.Rd);

    double inten = hit.deffuseR  * (cv::abs(n.ddot(l))) + hit.reflectCoefficience * pow(cv::abs(r.ddot(v)), s);
    //std::cout << "pow" << l<< std::endl;

    return inten;

}

static double Blinn_Phong(Hit hit, cv::Vec3d v_, double s)//光线的hit信息（入射光线，反射光线），视线方向
{
    cv::Vec3d l = hit.Pd;
    cv::Vec3d v = v_;
    cv::Vec3d n = hit.N;
    cv::Vec3d r = hit.Rd;
    cv::Vec3d h = (v + l)/2;

    double inten = hit.deffuseR + hit.reflectCoefficience * pow(norm(n.t() * h)/norm((n.t() * l)), s);

    return inten;
}


#endif //RAYTRACING_FUNCTIONS_H
