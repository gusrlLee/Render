#include <iostream>
#include <algorithm>
#include <cmath>

typedef struct Vector3
{
    float x, y, z;
} Vector3, Point3, Vertex;

typedef struct Ray
{
    Point3 origin;
    Vector3 direction;
} Ray;

typedef struct Triangle
{
    Vertex v0, v1, v2;
} Triangle;

int main()
{
    int w = 720, h = 480;
}
