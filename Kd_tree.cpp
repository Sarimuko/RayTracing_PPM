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

    *root = &nodes[cnt++];
    (*root) -> l = (*root) -> r = NULL;

    (*root) -> split = split;


    if (begin == end - 1)
    {
        (*root) -> isLeaf = true;
        (*root) -> data = data[begin];
        return;
    }

    std::cout << begin<< ' '<<mid <<' ' <<end<<std::endl;

    while (mid + 1 < end && ((cv::Vec3d)data[mid].P)[split] == ((cv::Vec3d)data[mid + 1].P)[split])
    {
        mid += 1;
    }

    (*root) -> data = data[mid];
    create(&((*root) -> l), data, begin, mid, (split + 1) % 3);
    create(&((*root) -> r), data, mid + 1, end, (split + 1) % 3);
}

std::vector<Hit> Kd_tree::findRange( Node *root, Hit target, double range)
{

    std::vector<Hit> ans;
    if(root == NULL)
        return ans;

    //std::cout << root -> data->P<<std::endl;
    double dist_sq, dx;

    //std::cout << (root -> data == NULL)<<std::endl;
    dist_sq = dist(root -> data.P, target.P);    //计算搜索路径中每个节点和target的距离
    //std::cout << "1"<<std::endl;

    if(dist_sq <= range && (sign((root -> data.P - target.P).ddot(target.N)) == 0)) {//将范围内的近邻添加到结果向量res_nearest中
        //std::pair<_Examplar,double> temp(root->getDomElt(), dist_sq);
        ans.push_back(root -> data);
        //结果个数+1
        //added_res = 1;
    }

    //std::cout << (root -> data == NULL)<<std::endl;
    switch (root -> split)
    {
        case 0: dx = target.P.x - root->data.P.x; break;
        case 1: dx = target.P.y - root->data.P.y; break;
        case 2: dx = target.P.z - root->data.P.z; break;
        default: break;
    }
    //dx = ((cv::Vec3d)(target.P))[root->split] - ((cv::Vec3d)(root->data -> P))[root->split];
    //std::cout << "2"<<std::endl;
    //左子树或右子树递归的查找
    std::vector<Hit> ret;
    ret = findRange(dx <= 0.0 ? root->l : root->r, target, range);
    //当另外一边可能存在范围内的近邻
    if(fabs(dx) < range) {
        ans.insert(ans.end(), ret.begin(), ret.end());
        ret = findRange(dx <= 0.0 ? root-> r : root-> l, target, range);
    }

    ans.insert(ans.end(), ret.begin(), ret.end());

    return ans;        //最终返回范围内的近邻集合
}

void Kd_tree::create(std::vector<Hit> data)
{
    cnt = 0;
    create(&root, data, 0, data.size(), 0);
}

std::vector<Hit> Kd_tree::findRange(Hit target, double range)
{
    return findRange(root, target, range);
}