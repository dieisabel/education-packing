#pragma once
#ifndef _PACKING_H
#define _PACKING_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "./figure.h"
#include "./packing_field.h"

using namespace std;
using namespace sf;


class Packing
{

private:
    RenderWindow _window;
    PackingField _packingField;
    Vector2i _mousePos;

public:
    Packing(int width, int height);

    void run();

};


#endif
