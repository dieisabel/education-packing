#pragma once
#ifndef _STATUS_BAR_H
#define _STATUS_BAR_H

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class StatusBar
{

private:
    Font _font;
    Text _text;
    Text _figureVars;

    Font loadFont(string path);

public:
    void set(string path);

    void overflow(int value, int maxValue);
    void normal(int value, int maxValue);
    void update(RenderWindow &window, int radius);

};

#endif
