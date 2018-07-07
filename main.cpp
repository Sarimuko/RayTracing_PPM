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

cv::Point3d Dx(1, 0, 0), Dy(0, 1, 0), Dz(0, 0, 1), O(0, 0, 0);

int main() {
    Camera camera(12, 5, 3, -1, 0, 0, 5);
    //.camera.applyDepth = true;
    camera.focusD = 7.5;
    camera.radius = 0.005;

    Scene scene;

    Ball ball(5, 5, 1.5, 1.5, 0);
    Ball ball_small(1, 10, 0.2, 0.2, 1);

    ball.r = 0;
    ball.g = ball.b = 0;

    ball_small.b = 200;
    ball_small.r = ball_small.g = 0;

    ball.refractR = 0.95;
    ball.reflectR = 0.05;

    Plane back(O, Dy, Dz);
    back.loadTexture("/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/texture/wall_tile.png");
    back.r = 255;
    back.g = 182;
    back.b = 193;
    Plane front(1, 0, 0, -20);
    front.r = 255;
    front.g = 182;
    front.b = 193;

    Plane left(0, 1, 0, 100);
    left.r = 255, left.g = 215, left.b = 0;

    Plane right(0, 1, 0, -100);
    right.r = 255, right.g = 215, right.b = 0;
    Plane down(O, Dx, Dy);
    down.r = 255, down.g = 215, down.b = 0;
    down.loadTexture("/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/texture/floor.bmp");
    Plane up(0, 0, 1, -100);
    up.r = 255, up.g = 215, up.b = 0;

    Plane drawing(cv::Point3d(0, -2, 0), Dy, Dz);
    drawing.hasBorder = true;
    drawing.len_x = 14; drawing.len_y = 9.34;
    drawing.loadTexture("/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/texture/drawing02.jpg");

    scene.addObject(&drawing);


    Bezier test, glass, lamp;

    test.loadTexture("/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/texture/vase.png");

    test.rou_d = 0.7;
    test.reflectR = test.refractR = 0;

    test.origin.x = 1;
    test.origin.y = 8;
    test.origin.z = 0;

    test.r = test.g = test.b = 255;

    cv::Point2d p1(5.31, 132.74);
    cv::Point2d p2(11.14, 96.01);
    cv::Point2d p3(22.34, 66.89);
    cv::Point2d p4(22.44, 54.8);
    cv::Point2d p5(14.08, 0.0);

    test.controlPoints.push_back(p5);
    test.controlPoints.push_back(p4);
    test.controlPoints.push_back(p3);
    test.controlPoints.push_back(p2);
    test.controlPoints.push_back(p1);

    test.scale = 30;
    test.rou_d = 0.3;
    test.spec = 0.3;

    test.init();

    glass.origin = cv::Point3d(1, 10, 0);
    glass.rou_d = 0;
    glass.refractR = 0.8;
    glass.reflectR = 0.1;
    glass.spec = 0;

    glass.scale = 30;

    glass.controlPoints.push_back(cv::Point2d(7.73, 0));
    glass.controlPoints.push_back(cv::Point2d(11.47, 0.5));
    glass.controlPoints.push_back(cv::Point2d(20.38, 6.3));
    glass.controlPoints.push_back(cv::Point2d(27.43, 17.5));
    glass.controlPoints.push_back(cv::Point2d(28.44, 23.25));
    glass.controlPoints.push_back(cv::Point2d(23.16, 44.19));
    glass.controlPoints.push_back(cv::Point2d(3.47, 68.97));
    glass.controlPoints.push_back(cv::Point2d(3.58, 71.8));
    glass.controlPoints.push_back(cv::Point2d(5.87, 78.4));;

    glass.init();

    lamp.origin = cv::Point3d(1, 10, 2.7);
    lamp.rou_d = 0.04;
    lamp.reflectR = 0;
    lamp.refractR = 0.01;
    lamp.scale = 30;


    lamp.controlPoints.push_back(cv::Point2d(39.047, 0));
    lamp.controlPoints.push_back(cv::Point2d(26.199, 64.69));

    lamp.loadTexture("/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/texture/lamp02.jpg");

    test.r = test.g = test.b = 255;

    lamp.init();


    scene.addObject(&lamp);
    scene.addObject(&glass);
    scene.addObject(&test);
    scene.addObject(&ball);
    scene.addObject(&ball_small);

    //scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);

    Light light(10, 10, 12, 1);
    scene.addLight(&light);

    Light light2(10, 0, 12, 1);
    scene.addLight(&light2);

    Light lampLight(1, 10, 3.7, 0.00004);
    scene.addLight(&lampLight);

    cv::Mat photo = camera.CreatePhoto(scene);
    cv::imshow("test", photo);
    cv::waitKey();

    cv::imwrite("/Users/wangyihan/Desktop/ComputerGraphics.png",photo);

    return 0;
}