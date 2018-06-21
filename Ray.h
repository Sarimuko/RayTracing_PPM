//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include <opencv2/opencv.hpp>
#include "Functions.h"


class Ray {
public:
    cv::Point3d p0;//出发点
    cv::Point3d pd;//方向

    double intensity;//强度，最开始的光线是1

    int rayType;//射线的种类

    double dis2(const cv::Point3d &p) const;

    Ray(cv::Point3d p0_, cv::Point3d pd_, int rayType = 0, double inten_ = 1): p0(p0_), pd(pd_), rayType(rayType), intensity(inten_)
    {
        pd = regu(pd);
    }
    Ray(){}

};


#endif //RAYTRACING_RAY_H
