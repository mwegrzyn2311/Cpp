#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>

#include "shape.h"
using namespace std;

namespace Shapes
{
enum class ShapeOperation
{
    INTERSECTION,
    SUM,
    DIFFERENCE
};

class ShapeComposite : public Shape
{
    std::shared_ptr<Shape> shape1, shape2;
    ShapeOperation operation;

public:
    ShapeComposite() = delete;
    ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation):Shape(0,0), shape1(move(shape1)), shape2(move(shape2)), operation(operation) { }

    bool isIn(int x, int y) const override;
};
} // namespace Shapes

#endif // SHAPECOMPOSITE_H
