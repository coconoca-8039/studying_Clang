#include <iostream>
#include "kapsel.h"
#include "kapsel.cpp"

using namespace std;

int main(){
    Sample s;
    s.setNum(5);
    cout << s.getNum() << endl;
    s.setNum(54321);
    cout << s.getNum() << endl;
    return 0;
}