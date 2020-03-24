//
// Created by user on 10.03.2020.
//

#include "Cone.h"
#include <iostream>
using namespace std;

Cone::Cone() : name("Default name") {
    this->height = this->defaultHeight;
    this->radius = this->defaultRadius;
    this->id = amount++;
}
Cone::Cone(int height, int radius, string newName) : name(newName) {
    this->height = height;
    this->radius = radius;
    this->id = amount++;
}
Cone::Cone(Cone& cone) : name(cone.name) {
    this->height = cone.height;
    this->radius = cone.radius;
    this->id = amount++;
}
int Cone::amount = 0;
const int Cone::defaultHeight = 20;

void Cone::read(ostream& os) {
    os<<"Cone '"<<this->name<<"' has id "<<this->id<<", height of "<<this->height<<" and radius of "<<this->radius<<endl;
}

void Cone::write(istream& is) {
    cout<<"Give new cone's height (current is: "<<this->height<<")"<<endl;
    is>>this->height;
    cout<<"Give new cone's radius (current is: "<<this->radius<<")"<<endl;
    is>>this->radius;
}

