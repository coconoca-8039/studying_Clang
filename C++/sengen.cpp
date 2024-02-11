#include <iostream> 
#include <stdio.h>
using namespace std;

template <typename T>
void printLine(const T& value) {
    cout << value << "\n";
}

int  main(){

    int num;
    num = 1;

    switch (num){
    case 10:
        cout << "kotoha" << "\n";
        break;

    case 1:
        cout << "kawaii" << "\n";
        break;
    
    default:
        cout << "aitai" << "\n";
        break;
    }

    return 0; 

}