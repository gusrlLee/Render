#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <random>

inline float Get1D()
{
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float Get1D(float min, float max)
{
    return min + ( max - min ) * Get1D();
}



#endif