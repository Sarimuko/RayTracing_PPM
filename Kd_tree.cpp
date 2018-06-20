//
// Created by wangyihan on 2018/6/19.
//

#include "Kd_tree.h"

void Kd_tree::create(Node** root, std::vector<Hit> data, int begin, int end, int split)//递归建立k-d tree
{
    if (begin >= end)
        return;

    std::vector<Hit>::iterator b = data.begin(), e = data.begin();
    b += begin;
    e += end;

    switch (split)
    {
        case 0: std::sort(b, e, cmp0); break;
        case 1: std::sort(b, e, cmp1); break;
        case 2: std::sort(b, e, cmp2); break;
        default: break;
    }

    int mid = (begin + end) / 2;

    *root = new Node();
    (*root) -> data = data[mid];


    if (begin == end - 1)
    {
        (*root) -> isLeaf = true;
        (*root) -> data = data[begin];
        return;
    }

    std::cout << begin<< ' '<<mid <<' ' <<end<<std::endl;

    create(&((*root) -> l), data, begin, mid, (split + 1) % 3);
    create(&((*root) -> r), data, mid, end, (split + 1) % 3);
}