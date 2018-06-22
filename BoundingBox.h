//
// Created by wangyihan on 2018/6/22.
//

#ifndef RAYTRACING_BOUNDINGBOX_H
#define RAYTRACING_BOUNDINGBOX_H


//#include "Vector3.h"
#include <opencv2/opencv.hpp>

class BoundingBox {
public:
    double boundary[6]; // lx rx ly ry lz rz
    BoundingBox();
    void include(cv::Vec3d p);
    void explode();
    bool contains(cv::Vec3d p) const;

    //friend std::ostream &operator<<(std::ostream &os, const BoundingBox &box);
};


#endif //RAYTRACING_BOUNDINGBOX_H
