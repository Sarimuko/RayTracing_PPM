cmake_minimum_required(VERSION 3.6)
project(RayTracing)
find_package(OpenCV)

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(DOpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include")
set(DOpenMP_CXX_LIB_NAMES "omp")
set(DOpenMP_omp_LIBRARY /usr/local/opt/libomp/lib/libomp.dylib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${DOpenMP_CXX_FLAGS}")

#FIND_PACKAGE(OpenMP)

#LINK_DIRECTORIES("matlab")

#add_subdirectory(texture)

set(SOURCE_FILES main.cpp Ray.cpp Ray.h Hit.h Object.cpp Object.h Scene.cpp Scene.h Camera.cpp Camera.h Light.cpp Light.h Functions.h const.h Kd_tree.cpp Kd_tree.h Bezier.cpp Bezier.h Polynomial.cpp Polynomial.h BoundingBox.cpp BoundingBox.h Texture.cpp Texture.h)
add_executable(RayTracing ${SOURCE_FILES})
target_link_libraries( RayTracing ${OpenCV_LIBS} ${DOpenMP_omp_LIBRARY})