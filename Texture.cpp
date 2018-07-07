//
// Created by wangyihan on 2018/6/22.
//

#include "Texture.h"
#include "Functions.h"

Texture::Texture() {data = NULL;}

Texture::Texture(const cv::Mat &mat)
{
    operator=(mat);
}

Texture::~Texture()
{
    if (data != NULL)
        delete[] data;
}

Texture &Texture::operator=(const cv::Mat &mat)
{
    if (data != NULL)
        delete[] data;
    data = new cv::Vec3b[mat.rows * mat.cols];
    h = mat.rows; w = mat.cols;

    return *this;
}

cv::Vec3b Texture::getColor(double x, double y) const
{
    x = min(max(x, 0), 1);
    y = min(max(y, 0), 1);
    y = (1 - y) * (h - 1);
    x = x * (w - 1);
    cv::Vec3b ans;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            int ny = y + i <= h? y + i: h;
            int nx = x + i <= w? x + j: w;
            ans += (1 - fabs(y - ny)) * (1 - fabs(x - nx)) * data[ny * w +  nx];
        }
    return ans;
}
