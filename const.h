//
// Created by wangyihan on 2018/5/27.
//

#ifndef RAYTRACING_CONST_H
#define RAYTRACING_CONST_H
#include <opencv2/opencv.hpp>



namespace CONST
{
    static const double s = 5;
    static const double a = 0.5;

    static int w = 640;
    static int h = 480;

    static double lens_w = 6.4;
    static double lens_h = 4.8;

    static int MAX_ITER = 2;

    static double pi = 3.1415926;
    static double rou = 0.5;

    static double EPS = 1e-5;
    static double INF = 1e50;

    static int PHOTON_PER_ITER = 100000;

}

#endif //RAYTRACING_CONST_H
