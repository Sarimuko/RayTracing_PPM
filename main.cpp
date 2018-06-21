#include <iostream>
#include "Camera.h"
#include "Functions.h"
#include "const.h"
#include "Hit.h"
#include "Light.h"
#include "Object.h"
#include "Ray.h"
#include "Scene.h"
#include "Kd_tree.h"
#include "Bezier.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;

    /*Camera camera(1999, 500, 500, -1, 0, 0, 500);
    Scene scene;

    Ball ball(50, 500, 150, 100, 0);
    Ball ball_small(200, 190, 200, 30, 1);

    ball.r = 0;
    ball.g = ball.b = 0;

    ball_small.b = 200;
    ball_small.r = ball_small.g = 0;

    //ball.refractR = 0.4;
    //ball_small.refractR = 0.6;

    Plane back(1, 0, 0, 0);
    back.r = 255;
    back.g = 182;
    back.b = 193;
    Plane front(1, 0, 0, -2000);
    front.r = 255;
    front.g = 182;
    front.b = 193;

    Plane left(0, 1, 0, 0);
    left.r = 255, left.g = 215, left.b = 0;

    Plane right(0, 1, 0, -1000);
    right.r = 255, right.g = 215, right.b = 0;
    Plane down(0, 0, 1, 0);
    down.r = 255, down.g = 215, down.b = 0;
    Plane up(0, 0, 1, -1000);
    up.r = 255, up.g = 215, up.b = 0;

    scene.addObject(&ball);
    scene.addObject(&ball_small);

    scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);




    Light light(1000, 500, 999, 0.7);
    scene.addLight(&light);

    cv::Mat photo = camera.CreatePhoto(scene);
    cv::imshow("test", photo);
    cv::waitKey();

    cv::imwrite("/Users/wangyihan/Desktop/ComputerGraphics.png",photo);*/

    /*Kd_tree test;
    Hit hit1;
    Hit hit2;
    hit1.P.x = 3;
    hit1.P.y = 4;
    hit1.P.z = 1;

    hit2.P.x = 4;
    hit2.P.y = 14;
    hit2.P.z = 6;

    std::vector<Hit>hits;
    hits.push_back(hit1);
    hits.push_back(hit2);*/

    //DataType data1(3,5,1);
    //DataType data2(5,1,5);

    /*std::vector<Data> datas;
    datas.push_back(data1);
    datas.push_back(data2);

    Node* root = NULL;*/
    /*Node* root = NULL;

    Hit target;
    target.P.x = 0;
    target.P.y = 0;
    target.P.z = 0;

    test.create(&root, hits, 0, 2, 0);
    std::vector<Hit*> ans = test.findRange(root, target, 6);
    std::cout << ans.size()<<std::endl;*/

    Bezier test;

    test.origin.x = test.origin.y = 100;
    test.origin.z = 0;
    cv::Point2d p1(29.2, 4.2);
    cv::Point2d p2(32.5, 16.6);
    cv::Point2d p3(27.5, 28.1);
    cv::Point2d p4(26.9, 40.6);

    test.controlPoints.push_back(p1);
    test.controlPoints.push_back(p2);
    test.controlPoints.push_back(p3);
    test.controlPoints.push_back(p4);

    test.init();

    Ray ray;
    cv::Point3d P(0, 0, 30);
    cv::Point3d Pd(1, 1, 0);
    ray.p0 = P;
    ray.pd = Pd;

    Hit hit = test.RayCast(ray);

    std::cout << hit.t << " "<< hit.N<<std::endl;
    return 0;
}