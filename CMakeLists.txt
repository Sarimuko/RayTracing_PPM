cmake_minimum_required(VERSION 3.6)
project(RayTracing)
find_package(OpenCV)

include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#LINK_DIRECTORIES("matlab")

#add_subdirectory(texture)

set(SOURCE_FILES main.cpp Ray.cpp Ray.h Hit.h Object.cpp Object.h Scene.cpp Scene.h Camera.cpp Camera.h Light.cpp Light.h Functions.h const.h Kd_tree.cpp Kd_tree.h Bezier.cpp Bezier.h Polynomial.cpp Polynomial.h BoundingBox.cpp BoundingBox.h Texture.cpp Texture.h)
add_executable(RayTracing ${SOURCE_FILES})
target_link_libraries( RayTracing ${OpenCV_LIBS} )

