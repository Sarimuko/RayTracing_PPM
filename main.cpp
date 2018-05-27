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

    Camera camera(0, 0, 0, 1, 1, 1, 2);
    Scene scene;

    Ball ball(30, 30, 30, 5, 0);
    scene.addObject(&ball);

    Light light(30, 30, 100, 1);
    scene.addLight(&light);

    cv::Mat photo = camera.CreatePhoto(scene);
    return 0;
}