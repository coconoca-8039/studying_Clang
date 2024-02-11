#include <iostream> 
#include <stdio.h>
#include<iomanip>
using namespace std;

template <typename T>
void printLine(const T& value) {
    cout << value << "\n";
}

int main(){
    int num = 1;
    int count = 0;
    while(num < 1000){
        num *= 2;
        count++;
        cout << count << "回目:" << num << "\n";
    }   
    cout << count << "回目で1000を超えます\n";

    int tmp = 1;

    do{
        cout << tmp << "回目の処理\n";
        tmp++;
    }while(tmp < 5);

    return 0;
}