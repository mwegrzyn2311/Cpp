#include "circle.h"

using namespace std;
using namespace Shapes;

bool Circle::isIn(int x, int y) const {
    int distToCenterQuad = (x-lowerLeftPoint.first)*(x-lowerLeftPoint.first)+(y-lowerLeftPoint.second)*(y-lowerLeftPoint.second);
    return (distToCenterQuad <= radius*radius);
}