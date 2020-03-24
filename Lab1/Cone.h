//
// Created by user on 10.03.2020.
//

#ifndef LAB1_CONE_H
#define LAB1_CONE_H

#include <iostream>
using namespace std;

class Cone {
private:
    int height;
    int radius;
    int id;
    const string name;
    static int amount;
    const static int defaultHeight;
    constexpr static int defaultRadius = 5;
public:
    Cone();
    Cone(int height, int radius = 5, string newName="Default name");
    Cone(Cone& cone);

    const int getHeight() { return this->height; }
    const int getRadius() { return this->radius; }

    void setHeight(int newHeight) { this->height = newHeight; }
    void setRadius(int newRadius) { this->radius = newRadius; }

    void print() {
        cout<<"Cone '"<<this->name<<"' has id "<<this->id<<", height of "<<this->height<<" and radius of "<<this->radius<<endl;
    }

    static int getAmountOfCones() { return amount; }

    ~Cone() { amount--; }

    void read(ostream& is);

    void write(istream& in);
};

#endif //LAB1_CONE_H
