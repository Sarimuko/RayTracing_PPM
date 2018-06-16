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

    Camera camera(400, 500, 500, -1, 0, 0, 50);
    Scene scene;

    Ball ball(30, 500, 500, 200, 0);

    ball.r = 200;
    ball.g = ball.b = 0;

    Plane back(1, 0, 0, 0);
    Plane front(1, 0, 0, -1000);
    Plane left(0, 1, 0, 0);
    Plane right(0, 1, 0, -1000);
    Plane down(0, 0, 1, 0);
    Plane up(0, 0, 1, -1000);

    scene.addObject(&ball);
    scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);




    Light light(900, 500, 980, 1);
    scene.addLight(&light);

    cv::Mat photo = camera.CreatePhoto(scene);
    cv::imshow("test", photo);
    cv::waitKey();

    cv::imwrite("/Users/wangyihan/Desktop/ComputerGraphics.png",photo);

    return 0;
}