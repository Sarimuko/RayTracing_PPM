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

    Camera camera(1, 1, 1, 1, 1, 1, 2);
    Scene scene;

    Ball ball(30, 30, 30, 5, 0);
    Plane back(1, 0, 0, 0);
    Plane front(1, 0, 0, -100);
    Plane left(0, 1, 0, 0);
    Plane right(0, 1, 0, -100);
    Plane down(0, 0, 1, 0);
    Plane up(0, 0, 1, -100);

    scene.addObject(&ball);
    scene.addObject(&back);
    scene.addObject(&front);
    scene.addObject(&left);
    scene.addObject(&right);
    scene.addObject(&down);
    scene.addObject(&up);


    Light light(30, 30, 100, 1);
    scene.addLight(&light);

    cv::Mat photo = camera.CreatePhoto(scene);
    cv::imshow("test", photo);
    cv::waitKey();
    return 0;
}