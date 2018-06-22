//
// Created by wangyihan on 2018/6/22.
//

#ifndef RAYTRACING_TEXTURE_H
#define RAYTRACING_TEXTURE_H

#include <opencv2/opencv.hpp>


class Texture {
public:
    cv::Vec3b *data;
    Texture(const cv::Mat &mat);
    Texture();
    Texture& operator=(const cv::Mat &mat);
    cv::Vec3b* operator[](int idx)const{return data + idx * cols;}
    cv::Vec3b getColor(double x, double y) const;

    virtual ~Texture();

    int rows, cols;
};


#endif //RAYTRACING_TEXTURE_H
