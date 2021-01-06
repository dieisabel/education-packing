#pragma once
#ifndef _PACKING_FIELD_H
#define _PACKING_FIELD_H

#include "./field.h"
#include "./status_bar.h"
#include "./figure.h"
#include "../utils/figure_vars.cpp"


class PackingField
{

private:
    Field _field;
    Figure _figure;
    StatusBar _statusBar;

    int _value;
    int _maxValue;

public:
    PackingField(int width, int height);

    void changeLimit(int value);
    void changeRadius(int value);
    void create(int x, int y);
    void del(int x, int y);
    void update(RenderWindow &window);

};


#endif
