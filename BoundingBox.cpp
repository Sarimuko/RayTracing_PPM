//
// Created by wangyihan on 2018/6/22.
//

#include "BoundingBox.h"
#include "const.h"
#include "Functions.h"

BoundingBox::BoundingBox()
{
    for (int i = 0; i < 3; ++i)
        boundary[i * 2] = CONST::INF, boundary[i * 2 + 1] = -CONST::INF;
}

void BoundingBox::include(cv::Vec3d p)
{
    for (int i = 0; i < 3; ++i) {
        boundary[i * 2] = min(boundary[i * 2], p[i]);
        boundary[i * 2 + 1] = max(boundary[i * 2 + 1], p[i]);
    }
}

bool BoundingBox::contains(cv::Vec3d p) const
{
    bool res = true;
    for (int i = 0; i < 3 && res; ++i)
        res &= (sign(boundary[i * 2] - p[i]) <= 0 && sign(p[i] - boundary[i * 2 + 1]) <= 0);
    return res;
}

void BoundingBox::explode()
{
    for (int i = 0; i < 3; ++i) {
        double len = boundary[i * 2 + 1] - boundary[i * 2];
        boundary[i * 2] -= len * 0.1;
        boundary[i * 2 + 1] += len * 0.1;
    }
}
