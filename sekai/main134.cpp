#include <iostream>
#include "car134.h"
#include "car134.cpp"
using namespace std;

int main(){
    Car tesla;
    tesla.setSpeed(100);
    tesla.drive(1.5);
    tesla.setSpeed(50);
    tesla.drive(2);
    cout << "移動距離 : " << tesla.getMigration() << "km" << endl;
    return 0;
}