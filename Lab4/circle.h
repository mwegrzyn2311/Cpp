#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
    int radius;
public:
    Circle() = delete;
    Circle(int centerX, int centerY, int radius):Shape(centerX, centerY), radius(radius) {}
    bool isIn(int x, int y) const override;
    int getRadius() const { return radius; }
};
} // namespace Shapes

#endif // CIRCLE_H
