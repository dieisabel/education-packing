#include "../headers/packing_field.h"


PackingField::PackingField(int width, int height)
    : _figure(), _field(width, height, {width / 2, height / 2}), 
      _statusBar("./assets/fonts/montserrat-regular.ttf")
{
    _value = 0;
    _maxValue = 20000;
}


void PackingField::changeLimit(int value)
{
    if (_maxValue + value > 0)
    {
        _maxValue += value;
    }
}

void PackingField::changeRadius(int value)
{
    if (_figure.getRadius() + value > 0)
    {
        _figure.increase(value);
    }
}

void PackingField::create(int x, int y)
{
    FigureVars figure = _figure.create(x, y);
    if (_value < _maxValue)
    {
        if (_field.place(figure))
        {
            _value += figure.area;
        }
    }
}

void PackingField::del(int x, int y)
{
    bool flag = false;
    FigureVars tmp = _field.del(flag, x, y, 20);
    if (flag)
    {
        _value -= tmp.area;
    }
}

void PackingField::update(RenderWindow &window)
{
    if (_value >= _maxValue) {
        _statusBar.overflow(_value, _maxValue);
    } else {
        _statusBar.normal(_value, _maxValue);
    }

    _statusBar.update(window, _figure.getRadius());
    _field.update(window);
}
