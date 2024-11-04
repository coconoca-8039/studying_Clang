#include "setter114.h"
#include <iostream>
using namespace std;

void Sample::func1(){
    cout << "func1" << endl;
    a = 1;
    b = 1;
    func2();  // func1内からfunc2を呼び出す
}

void Sample::func2(){
    a = 200;
    b = 2;
    cout << "a=" << a << "," << "b=" << b << endl;
}