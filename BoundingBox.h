//
// Created by wangyihan on 2018/6/22.
//

#ifndef RAYTRACING_BOUNDINGBOX_H
#define RAYTRACING_BOUNDINGBOX_H


//#include "Vector3.h"
#include <opencv2/opencv.hpp>
#include "Ray.h"

class BoundingBox {
public:
    double boundary[6];
    BoundingBox();
    void include(cv::Vec3d p);
    bool contains(cv::Vec3d p) const;

    bool intersect(Ray ray);
};


#endif //RAYTRACING_BOUNDINGBOX_H
