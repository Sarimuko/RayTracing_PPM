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
    rows = mat.rows; cols = mat.cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cv::Vec3b tmp = mat.at<cv::Vec3b>(i, j);
            std::swap(tmp[0], tmp[2]);
            data[i * cols + j] = tmp;
        }
    }
    return *this;
}

cv::Vec3b Texture::getColor(double x, double y) const
{
    x = min(max(x, 0.), 1.);
    y = min(max(y, 0.), 1.);
    y = (1 - y) * (rows - 1);
    x = x * (cols - 1);
    cv::Vec3b res;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            int ny = std::min(int(y) + i, this->rows);
            int nx = std::min(int(x) + j, this->cols);
            res += (1 - fabs(y - ny)) * (1 - fabs(x - nx)) * (*this)[ny][nx];
        }
    return res;
}
