//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H
#include <opencv2/opencv.hpp>
#include "Scene.h"



class Camera {
public:
    cv::Point3d position;//摄像机位置
    cv::Point3d direction;//视线方向

    cv::Point3d Dx, Dy, Dz;

    double xscale = 0.1, yscale = 0.1;//x, y两个方向的放缩系数


    double fD;//视平面距离

    bool applyDepth = false;//默认不使用景深
    int sample = 2;//使用景深时的采样数量

    double focusD;//焦平面距离
    double radius;//光圈大小


    cv::Mat CreatePhoto(Scene& scene);//to do
    cv::Mat CreatePhotoPT(Scene& scene);//basic function


    double getPixelLength(const cv::Vec3d &P);
    Ray ProduceRay(cv::Point3d p);//produce a ray from camera to point p

    Camera(double px, double py, double pz, double dx, double dy, double dz, double fd)
    {
        fD = fd;

        position.x = px;
        position.y = py;
        position.z = pz;

        direction.x = dx;
        direction.y = dy;
        direction.z = dz;

        direction = regu(direction);
    }

};



#endif //RAYTRACING_CAMERA_H
