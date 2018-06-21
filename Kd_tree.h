//
// Created by wangyihan on 2018/6/19.
//

#ifndef RAYTRACING_KD_TREE_H
#define RAYTRACING_KD_TREE_H

#include <opencv2/core/types.hpp>
#include <vector>
#include "Hit.h"
#include "Functions.h"


struct Node
{
    //cv::Point3d P;//分割点的坐标，x,y,z
    bool isLeaf;

    Hit data;

    int split;//分割维数， 0/1/2
    Node* l = NULL, *r = NULL;

};

class Kd_tree
{
public:
    int k;//dimension

    Node* root = NULL;


    //void insert(Node* node);
    void create(std::vector<Hit> data);
    void create(Node** root, std::vector<Hit> data, int begin, int end, int split);//建立
    std::vector<Hit> findRange(Node* root, Hit target, double range);
    std::vector<Hit> findRange(Hit target, double range);
    //void addPhoton(Node* root, Hit target, double range);//添加光子
};


#endif //RAYTRACING_KD_TREE_H
