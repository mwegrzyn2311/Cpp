#include <iostream>
#include "shapecomposite.h"

using namespace std;
using namespace Shapes;

bool ShapeComposite::isIn(int x, int y) const {
    switch(operation) {
        case ShapeOperation::INTERSECTION:
            return (shape1->isIn(x,y) && shape2->isIn(x,y));
        case ShapeOperation::SUM:
            return (shape1->isIn(x,y) || shape2->isIn(x,y));
        case ShapeOperation::DIFFERENCE:
            return (shape1->isIn(x,y) != shape2->isIn(x,y));
        default:
            return false;
    }
}