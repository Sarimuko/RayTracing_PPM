#include <iostream>
#include "Camera.h"
#include "Functions.h"
#include "const.h"
#include "Hit.h"
#include "Light.h"
#include "Object.h"
#include "Ray.h"
#include "Scene.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;

    Camera camera(19999, 5000, 5000, -1, 0, 0, 1000);
    Scene scene;

    Ball ball(500, 5000, 1500, 1000, 0);
    Ball ball_small(2000, 1900, 2000, 300, 1);

    ball.r = 200;
    ball.g = ball.b = 0;

    ball_small.b = 200;
    ball_small.r = ball_small.g = 0;

    ball.refractR = 0.4;
    //ball_small.refractR = 0.6;

    Plane back(1, 0, 0, 0);
    Plane front(1, 0, 0, -20000);
    Plane left(0, 1, 0, 0);
    Plane right(0, 1, 0, -10000);
    Plane down(0, 0, 1, 0);
    Plane up(0, 0, 1, -10000);

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

    return 0;
}