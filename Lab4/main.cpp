#include <iostream>
#include <gtest/gtest.h>

#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"

#include "shape.h"
#include "stage.h"
#include "rectangle.h"
#include "circle.h"
#include "shapecomposite.h"

using namespace std;
using namespace Shapes;

void realDraw() {
    constexpr int stageWidth = 700, stageHeight = 700;
    constexpr int homeWidth = stageWidth*6/10, homeHeight = stageHeight*6/10;
    constexpr int homeXFrom = (stageWidth-homeWidth)/2, homeXTo = homeXFrom+homeWidth, homeYFrom = (stageHeight-homeHeight)/20, homeYTo = homeYFrom + homeHeight;
    shared_ptr<Shape> home(new Rectangle(homeXFrom, homeYFrom, homeXTo, homeYTo));

    constexpr int homeXCenter = homeXFrom + homeWidth/2, roofHeight = homeWidth*5/8;
    shared_ptr<Shape> roofMaterial(new Circle(homeXCenter, homeYTo, roofHeight));

    constexpr int cutFromX = homeXCenter-roofHeight, cutFromY = homeYTo,
        cutToX = homeXCenter+roofHeight, cutToY = homeYTo+roofHeight;
    shared_ptr<Shape> cutFromRoof(new Rectangle(cutFromX, cutFromY, cutToX, cutToY));

    shared_ptr<Shape> roof(new ShapeComposite(roofMaterial, cutFromRoof, ShapeOperation::INTERSECTION));

    shared_ptr<Shape> homeWithRoof(new ShapeComposite(home, roof, ShapeOperation::SUM));

    constexpr int doorXFrom = homeXFrom + homeWidth/6, doorXTo = doorXFrom + homeWidth/4;
    constexpr int doorYFrom = homeYFrom + homeHeight/20, doorYTo = doorYFrom + homeHeight*7/10;
    shared_ptr<Shape> door(new Rectangle(doorXFrom, doorYFrom, doorXTo, doorYTo));

    shared_ptr<Shape> homeWithDoor(new ShapeComposite(homeWithRoof, door, ShapeOperation::DIFFERENCE));

    constexpr int doorWidth = doorXTo - doorXFrom, doorHeight = doorYTo - doorYFrom;
    constexpr int windowXFrom = homeXTo - homeWidth*6/10 + doorWidth*6/10;
    constexpr int windowXTo = windowXFrom + doorWidth*5/4;
    constexpr int windowYFrom = doorYFrom + doorHeight*4/10;
    constexpr int windowYTo = windowYFrom + + (windowXTo - windowXFrom)*6/5;
    shared_ptr<Shape> window(new Rectangle(windowXFrom, windowYFrom, windowXTo, windowYTo));
    shared_ptr<Shape> homeWithDoorAndWindow(new ShapeComposite(homeWithDoor, window, ShapeOperation::DIFFERENCE));

    const Stage stage(stageWidth, stageHeight);
    stage.drawShapeToPng(homeWithDoorAndWindow.get(), "domek.png");
}

int main(int argc, char* argv[])
{
    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    realDraw();

    return RUN_ALL_TESTS();
}
