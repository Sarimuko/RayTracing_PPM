//
// Created by wangyihan on 2018/6/21.
//

#ifndef RAYTRACING_BEZIER_H
#define RAYTRACING_BEZIER_H
#include "Object.h"
#include "Polynomial.h"
#include <utility>
#include "BoundingBox.h"


class Bezier: public Object
{
public:

    BoundingBox boundingBox;

    std::vector<cv::Point2d> controlPoints;
    int cpCnt;//控制点及个数
    void init();

    cv::Point3d Dz, Dx, Dy;

    Polynomial px, py, pz, dpx, dpy;


    cv::Vec3b getColor(cv::Point3d P);
    cv::Point3d getPoint(double t, double theta);//得到某个点的坐标
    cv::Point2d getCurve(double t);//得到曲线的坐标（割平面）
    std::pair<Polynomial, Polynomial> P2d(int l, int n);

    Hit RayCast(Ray ray);

    bool Intersect(Ray ray);
};

#endif //RAYTRACING_BEZIER_H
