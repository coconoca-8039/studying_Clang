#include <iostream> 
#include <stdio.h>
#include<iomanip>
using namespace std;

template <typename T>
void printLine(const T& value) {
    cout << value << "\n";
}

void kotoha();

void hanon(int x){
    for(int i = 0; i < x; i++){
        cout << "kotoha\n";
    }
}

int capi(int c, int z){
    int tmp;
    tmp = 2 * c * z;
    return tmp;
}

int main(){
    kotoha();
    hanon(4);

    int cccc;
    cccc = capi(3, 3);
    cout << cccc << "\n";
}

void kotoha(){
    cout << "Kotoha\n";
}
