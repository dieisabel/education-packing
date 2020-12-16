#include "./math.h"


int Math::calculateDistance(Point point_1, Point point_2)
{
    float formula = (pow((point_2.x - point_1.x), 2) +
                    (pow((point_2.y - point_1.y), 2)));
    return sqrt(abs(formula));
}

void Math::calculateCircle(Point points[], int radius, Point position)
{
    float radian;

    for (int i = 0; i < 360; i++)
    {
        radian = i * (M_PI / 180);
        points[i].x = position.x + radius * cos(radian);
        points[i].y = position.y + radius * sin(radian);
    }
}

void Math::calculateRectangle(Point points[], Point center, 
                              int width, int height)
{
    points[0] = {center.x - width / 2, center.y - height / 2};
    points[1] = {center.x + width / 2, center.y - height / 2};
    points[2] = {center.x + width / 2, center.y + height / 2};
    points[3] = {center.x - width / 2, center.y + height / 2};
    points[4] = {center.x - width / 2, center.y - height / 2};
}

int Math::calculateArea(int radius)
{
    return M_PI * radius * radius;
}
