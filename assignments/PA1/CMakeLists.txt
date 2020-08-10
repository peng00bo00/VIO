cmake_minimum_required(VERSION 2.8)

project(EX1)
set(CMAKE_BUILD_TYPE "Release")

Find_Package(Eigen3 REQUIRED)
Find_Package(Sophus REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(exercise exercise.cpp)