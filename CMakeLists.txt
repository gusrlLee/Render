cmake_minimum_required(VERSION 3.30)

project(render)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenMP REQUIRED)

add_subdirectory(thirdparty)

add_subdirectory(pt)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
target_link_libraries(${PROJECT_NAME} tinyobjloader)
