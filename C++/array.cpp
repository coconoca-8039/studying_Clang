#include <iostream> 
#include <stdio.h>
#include<iomanip>
using namespace std;

void keisan(int x[]){
    int i;
    int sum = 0;
    for(i = 0; i < 3; i++){
        sum += x[i];
    }
    cout << "平均点は" << sum/3 << "です\n";
}

int main(){
    int array[3];
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    cout << array[0] << "\n";
    cout << array[1] << "\n";
    cout << array[2] << "\n";

    int xxxx[3] = {11, 22, 33};
    cout << xxxx[0] << "\n";
    cout << xxxx[1] << "\n";
    cout << xxxx[2] << "\n";

    int yyyy[] = {111, 222, 333};
    cout << yyyy[0] << "\n";
    cout << yyyy[1] << "\n";
    cout << yyyy[2] << "\n";

    int kotoha[5] = {10, 20, 30, 40 ,50};
    int i;
    for(i = 0; i < 5; i++){
        cout << i << "番目：" << kotoha[i] << "\n";
    }

    int capi[3] = {77, 88, 99};
    keisan(capi);

    return 0;

}