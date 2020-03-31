#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
using namespace std;

namespace Shapes
{
class Rectangle : public Shape
{
    Point upperRightPoint;
public:
    Rectangle() = delete;
    Rectangle(int fromX, int fromY, int toX, int toY): Shape(fromX, fromY), upperRightPoint(toX, toY) {}
    bool isIn(int x, int y) const override {
        return (x >= lowerLeftPoint.first && x <= upperRightPoint.first && y >= lowerLeftPoint.second && y <= upperRightPoint.second);
    }
    int getXTo() const { return upperRightPoint.first; }
    int getYTo() const { return upperRightPoint.second; }
};
} // namespace Shapes

#endif // RECTANGLE_H
