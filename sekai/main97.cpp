#include <iostream>
#include "car96.h"
#include "car97.cpp"
#define NEWLINE std::cout << std::endl

using namespace std;

int main(int argc, char** argv){
    Car car;
    car.name = "86";
    car.speed = 40;
    car.drive(1.5);
    NEWLINE;

    Car kotoha;
    kotoha.name = "note";
    kotoha.speed = 100;
    kotoha.drive(100);

    return 0;
}
