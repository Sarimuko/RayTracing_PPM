//
// Created by wangyihan on 2018/5/19.
//

#include "Ray.h"

double Ray::dis2(const cv::Point3d &p) const {
    if ((p - p0).dot(pd) > 0) return (cv::norm((p - p0).cross(pd)) / cv::norm(pd)) * (cv::norm((p - p0).cross(pd)) / cv::norm(pd));//锐角
    else return (cv::norm(p - p0)) * (cv::norm(p - p0));
}