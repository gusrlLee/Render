cmake_minimum_required(VERSION 3.30)

project(render)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenMP REQUIRED)
find_package(embree REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} embree)
target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
