//
// Created by wangyihan on 2018/5/19.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H
#include <opencv2/opencv.hpp>
#include "Scene.h"



class Camera {
private:
    cv::Point3d position;//摄像机位置
    cv::Point3d direction;//视线方向


    double fD;//视平面距离

public:
    cv::Mat CreatePhoto(Scene& scene);//to do
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
