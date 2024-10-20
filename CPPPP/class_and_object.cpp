#include <iostream>
#include "car.h"
#include "car.cpp"

using namespace std;

int main(){
    Car note;
    note.name = "note";
    note.speed = 40;
    note.drive(1.5);

    cout << endl;  // 改行

    Car GTR;
    GTR.name = "GTR";
    GTR.speed = 100;
    GTR.drive(1.5);


    return 0;
}