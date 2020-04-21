#include <iostream>
#include "stage.h"
#include "shape.h"
#include <gd.h>

using namespace Shapes;
using namespace std;

void Stage::drawShape2Stream(const Shape* shape, ostream& stream) const {
    for(int j = height; j > 0; j--) {
        for(int i = 1; i <= width; i++) {
            if(shape->isIn(i,j)) {
                stream<<shapeSymbol;
            } else {
                stream<<emptySymbol;
            }
        }
        stream<<endl;
    }
}
void Stage::drawShapeToPng(const Shapes::Shape* shape, std::string filename) const {
    gdImagePtr image = gdImageCreate(width*multX, height*multY);
    int emptyColor = gdImageColorAllocate (image,get<0>(emptyRGB), get<1>(emptyRGB), get<2>(emptyRGB));
    int shapeColor = gdImageColorAllocate (image,get<0>(shapeRGB), get<1>(shapeRGB), get<2>(shapeRGB));
    for(int j = 1; j <= height; j++) {
        for(int i = 0; i < width; i++) {
            if(shape->isIn(i,j)) {
                gdImageFilledRectangle(image, i*multX, (height-j)*multY, (i+1)*multX, (height-j+1)*multY, shapeColor);
            } else {
                gdImageFilledRectangle(image, i*multX, (height-j)*multY, (i+1)*multX, (height-j+1)*multY, emptyColor);
            }
        }
    }
    FILE* imageFile = fopen(filename.c_str(), "w");
    gdImagePng(image, imageFile);
    fclose(imageFile);
}