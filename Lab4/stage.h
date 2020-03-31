#ifndef STAGE_H
#define STAGE_H

#include <iosfwd>
#include <tuple>

namespace Shapes
{
class Shape;
}

class Stage
{
    int width, height;
    constexpr static char emptySymbol{' '};
    constexpr static char shapeSymbol{'*'};
    std::tuple<int,int,int> emptyRGB;
    std::tuple<int,int,int> shapeRGB;
    int multX;
    int multY;

public:
    Stage(int width, int height, std::tuple<int,int,int> emptyRGB = std::make_tuple(255,255,255), std::tuple<int,int,int> shapeRGB = std::make_tuple(0,0,0), int multX=1, int multY=1):
        width(width), height(height), emptyRGB(std::move(emptyRGB)), shapeRGB(std::move(shapeRGB)), multX(multX), multY(multY){}
    void setEmptyRGB(int r, int g, int b){ emptyRGB = std::make_tuple(r,g,b); }
    void setShapeRGB(int r, int g, int b){ shapeRGB = std::make_tuple(r,g,b); }
    void drawShape2Stream(const Shapes::Shape* shape, std::ostream& stream) const;
    void drawShapeToPng(const Shapes::Shape* shape, std::string filename) const;
};

#endif // STAGE_H
