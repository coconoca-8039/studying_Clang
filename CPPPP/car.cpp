#include "car.h"
#include <iostream>

using namespace std;

void Car::drive(double hour){
    cout << "車種" << name << endl;
    cout << "時速" << speed << "kmで" << hour << "時間走行" << endl;
    cout << speed * hour << "km移動しました" << endl;
}