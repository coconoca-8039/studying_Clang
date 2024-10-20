#include "car_134.h"
#include "car_134_sub.cpp"
#include <iostream>

using namespace std;

int  main(){
    Car car;
    car.setSpeed(100);
    car.drive(2);
    cout << car.getMigration() << endl;
}