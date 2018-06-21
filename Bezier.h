//
// Created by wangyihan on 2018/6/21.
//

#ifndef RAYTRACING_BEZIER_H
#define RAYTRACING_BEZIER_H


#include <ostream>
#include "Object.h"

class Bezier : public Object{
public:
    //BoundingBox bbox;
    //Polynomial px, py, dpx, dpy;//p(t)
    cv::Vec3d Dz, Dx, Dy, P;
    double S;
    std::vector<cv::Vec3d> control_points;

    cv::Vec3d getColor(const cv::Vec3d &P);

    Hit collide(const Ray &ray);

    //void input(const std::string &var, std::stringstream &ss) override;

    void init();

    cv::Point3d getN(double t, double theta);

    cv::Point3d getPoint(double t, double theta);

    //std::pair<Polynomial, Polynomial> P2d(int l, int n);

    friend std::ostream &operator<<(std::ostream &os, const Bezier &bezier);

    cv::Vec3d getColor(double t, double theta);

    //void generateMeshes(std::vector<Vector3> &points, std::vector<int4> &meshes) override;
};


#endif //RAYTRACING_BEZIER_H
