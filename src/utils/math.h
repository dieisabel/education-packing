#pragma once
#ifndef _MATH_SOMETHING_H
#define _MATH_SOMETHING_H

#include <cmath>

#include "./point.cpp"

#define _USE_MATH_DEFINES

class Math
{

public:
    int calculateDistance(Point point_1, Point point_2);
    void calculateCircle(Point points[], int radius, Point position);
    void calculateRectangle(Point points[], Point center, 
                            int width, int height);
    int calculateArea(int radius);
};

#endif
