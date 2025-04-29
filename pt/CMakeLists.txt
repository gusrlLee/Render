cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)

add_executable(pt pt.cpp)

target_include_directories(pt PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(pt OpenMP::OpenMP_CXX)
target_link_libraries(pt tinyobjloader)
