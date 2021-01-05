#include "../headers/field.h"


bool Field::checkIsFree(int x, int y, int radius)
{
    for (int i = 0; i < _figures.size(); i++)
    {
        if (!(calculateDistance(_figures[i].center, {x, y}) >
                                       _figures[i].radius + radius))
        {
            return false;
        }
    }
    return true;
}

bool Field::checkBorder(int x, int y, int radius)
{
    Point checkint = {x, y};

    bool check1 = _center.x - _width / 2 + radius < checkint.x;
    bool check2 = _center.y - _height / 2 + radius < checkint.y;

    bool check3 = checkint.x < _center.x + _width / 2 - radius;
    bool check4 = checkint.y < _center.y + _height / 2 - radius;

    if (check1 && check2 && check3 && check4)
    {
        return true;
    }
    return false;
}

void Field::set(int windowWidth, int windowHeight, Point center)
{
    _width  = windowWidth / 2;
    _height = windowHeight / 2;

    _center = center;
}

void Field::add(FigureVars figure)
{
    _figures.push_back(figure);
}

bool Field::place(FigureVars figure)
{
    if (checkBorder(figure.center.x, figure.center.y, figure.radius) &&
        checkIsFree(figure.center.x, figure.center.y, figure.radius))
    {
        add(figure);
        return true;
    }
    return false;
}

VertexArray Field::show()
{
    Point points[5];

    calculateRectangle(points, {_center.x, _center.y}, _width, _height);

    VertexArray rectangle(LineStrip, 0);

    for (int i = 0; i < 5; i++)
    {
        rectangle.append(Vertex(Vector2f(points[i].x,
                                         points[i].y),
                                Color::White));
    }

    return rectangle;
}

FigureVars Field::del(bool &flag, int x, int y, int radius)
{
    FigureVars tmp;
    for (int i = 0; i < _figures.size(); i++)
    {
        if (calculateDistance(_figures[i].center, {x, y}) <
                                     _figures[i].radius)
        {
            tmp = _figures[i];
            flag = true;
            _figures.erase(_figures.begin() + i);
            return tmp;
        }
    }
    return tmp;
}

void Field::update(RenderWindow &window)
{
    for (int i = 0; i < _figures.size(); i++)
    {
        window.draw(_figures[i].figure);
    }
    window.draw(show());
}
