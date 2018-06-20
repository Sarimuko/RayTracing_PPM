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

int main() {
    //std::cout << "Hello, World!" << std::endl;

    Camera camera(19999, 5000, 5000, -1, 0, 0, 1000);
    Scene scene;

    Ball ball(500, 5000, 1500, 1000, 0);
    Ball ball_small(2000, 1900, 2000, 300, 1);

    ball.r = 0;
    ball.g = ball.b = 0;

    ball_small.b = 200;
    ball_small.r = ball_small.g = 0;

    ball.refractR = 0.4;
    //ball_small.refractR = 0.6;

    Plane back(1, 0, 0, 0);
    back.r = 255;
    back.g = 182;
    back.b = 193;
    Plane front(1, 0, 0, -20000);
    front.r = 255;
    front.g = 182;
    front.b = 193;

    Plane left(0, 1, 0, 0);
    left.r = 255, left.g = 215, left.b = 0;

    Plane right(0, 1, 0, -10000);
    right.r = 255, right.g = 215, right.b = 0;
    Plane down(0, 0, 1, 0);
    down.r = 255, down.g = 215, down.b = 0;
    Plane up(0, 0, 1, -10000);
    up.r = 255, up.g = 215, up.b = 0;

    scene.addObject(&ball);
    scene.addObject(&ball_small);

    scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);




    Light light(10000, 5000, 9999, 0.7);
    scene.addLight(&light);

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
    hits.push_back(hit2);

    //DataType data1(3,5,1);
    //DataType data2(5,1,5);

    /*std::vector<Data> datas;
    datas.push_back(data1);
    datas.push_back(data2);

    Node* root = NULL;*/
    /*Node* root = NULL;

    test.create(&root, hits, 0, 2, 0);*/

    return 0;
}