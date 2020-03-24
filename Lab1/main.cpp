#include <iostream>
#include "Cone.h"

using namespace std;
int main() {
    Cone cone;
    cone.print();
    cout<<"There are currenty "<<cone.getAmountOfCones()<<" cones"<<endl;

    Cone cone1(30);
    cone1.print();
    cout<<"There are currenty "<<cone1.getAmountOfCones()<<" cones"<<endl;

    Cone cone2(44,44, "a imie jego czterdziesci i cztery");
    cone2.print();
    cout<<"There are currenty "<<cone2.getAmountOfCones()<<" cones"<<endl;

    Cone cone3 = cone;
    cone3.print();
    cout<<"There are currenty "<<cone3.getAmountOfCones()<<" cones"<<endl;

    cone3.setHeight(cone1.getHeight());
    cone3.setRadius(cone2.getRadius());
    cone3.print();
    cout<<"There are currenty "<<cone3.getAmountOfCones()<<" cones"<<endl;

    Cone cone4;

    cone4.write(cin);
    cone4.read(cout);

    return 0;
}