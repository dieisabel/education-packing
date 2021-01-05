#pragma once
#ifndef _FIGURES_H
#define _FIGURES_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../utils/point.cpp"
#include "../utils/math.h"
#include "../utils/figure_vars.cpp"

#define _USE_MATH_DEFINES

using namespace sf;
using namespace Math;


class Figure
{

private:
    int _radius = 20;

public:
    FigureVars create(int x, int y);

    int getRadius() { return _radius;};
    void increase(int value);
};

#endif
