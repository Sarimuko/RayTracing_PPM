//
// Created by wangyihan on 2018/5/20.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include <opencv2/opencv.hpp>
#include "Ray.h"


class Light {
    friend class Scene;
protected:
    cv::Point3d position;//光源的位置
    double intensity;//光源的强度

    int id;
public:
    Ray getRay(cv::Point3d p);//获得一条指向p的光线
    Light(double x, double y, double z, double inten)
    {
        position.x = x;
        position.y = y;
        position.z = z;

        intensity = inten;
    }

    Ray randomRay();
};


#endif //RAYTRACING_LIGHT_H
