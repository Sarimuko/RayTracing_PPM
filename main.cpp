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

    Camera camera(10, 5, 3, -1, 0, 0, 5);
    Scene scene;

    Ball ball(2, 8, 2, 1.5, 0);
    Ball ball_small(2, 1.9, 0.3, 0.3, 1);

    ball.r = 0;
    ball.g = ball.b = 0;

    ball_small.b = 200;
    ball_small.r = ball_small.g = 0;

    ball.refractR = 0.9;
    ball.reflectR = 0;
    //ball_small.refractR = 0.6;

    Plane back(1, 0, 0, 0);
    back.r = 255;
    back.g = 182;
    back.b = 193;
    Plane front(1, 0, 0, -20);
    front.r = 255;
    front.g = 182;
    front.b = 193;

    Plane left(0, 1, 0, 0);
    left.r = 255, left.g = 215, left.b = 0;

    Plane right(0, 1, 0, -10);
    right.r = 255, right.g = 215, right.b = 0;
    Plane down(0, 0, 1, 0);
    down.r = 255, down.g = 215, down.b = 0;
    Plane up(0, 0, 1, -10);
    up.r = 255, up.g = 215, up.b = 0;

    Bezier test;

    test.rou_d = 0.7;
    test.reflectR = test.refractR = 0;

    test.origin.x = test.origin.y = 10;
    test.origin.z = 0;
    cv::Point2d p1(2.92, 0.42);
    cv::Point2d p2(3.25, 1.66);
    cv::Point2d p3(2.75, 2.81);
    cv::Point2d p4(2.69, 4.06);

    test.controlPoints.push_back(p1);
    test.controlPoints.push_back(p2);
    test.controlPoints.push_back(p3);
    test.controlPoints.push_back(p4);

    test.init();

    //scene.addObject(&test);
    scene.addObject(&ball);
    scene.addObject(&ball_small);

    scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);




    Light light(3, 9, 6, 0.7);
    scene.addLight(&light);

    Light light2(3, 1, 6, 0.7);
    scene.addLight(&light2);

    cv::Mat photo = camera.CreatePhoto(scene);
    cv::imshow("test", photo);
    cv::waitKey();

    cv::imwrite("/Users/wangyihan/Desktop/ComputerGraphics.png",photo);

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

    /*Bezier test;

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

    std::cout << hit.t << " "<< hit.N<<std::endl;*/
    return 0;
}