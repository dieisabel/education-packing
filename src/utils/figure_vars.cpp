#ifndef _FIGURE_VARS_CPP
#define _FIGURE_VARS_CPP

#include <SFML/Graphics.hpp>

#include "./point.cpp"

using namespace sf;


struct FigureVars
{
    VertexArray figure;
    Point center;
    int area;
    int radius;
};

#endif
