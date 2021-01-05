#include "../headers/figure.h"


FigureVars Figure::create(int x, int y)
{
    FigureVars vars;
    Point points[360];
    calculateCircle(points, _radius, {x, y});
    VertexArray circle(LineStrip, 0);

    for (int i = 0; i < 360; i++)
    {
        circle.append(Vertex(Vector2f(points[i].x,
                                      points[i].y),
                      Color::White));
    }

    vars.figure = circle;
    vars.center = {x, y};
    vars.area = calculateArea(_radius);
    vars.radius = _radius;
    return vars;
}

void Figure::increase(int value)
{
    _radius += value;
}
