#pragma once
#ifndef _FIELD_H
#define _FIELD_H

#include <vector>
#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "../utils/point.cpp"
#include "../utils/math.h"
#include "../utils/figure_vars.cpp"

using namespace sf;
using namespace Math;


class Field
{

private:
    int _width;
    int _height;
    Point _center;

    std::vector<FigureVars> _figures;

    void add(FigureVars figure);
    bool checkBorder(int x, int y, int radius);
    bool checkIsFree(int x, int y, int radius);

public:
    Field(int windowWidth, int windowHeight, Point center);

    bool place(FigureVars figure);
    FigureVars del(bool &flag, int x, int y, int radius);
    VertexArray show();
    void update(RenderWindow &window);
};

#endif
