#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <iostream>

typedef struct Vector3
{
    float x, y, z;
} Vector3, Point3, Vertex;

typedef struct Color {
    float r, g, b;
} Color;

typedef struct Camera 
{
    Point3 position;
    Vector3 direction;
    Vector3 up;
    float focalLength;
} Camera;

typedef struct Ray
{
    Point3 origin;
    Vector3 direction;
} Ray;

typedef struct Triangle
{
    Vertex v0, v1, v2;
    int matIdx;
} Triangle;

#endif