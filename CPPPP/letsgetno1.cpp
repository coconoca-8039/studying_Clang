#include <iostream>

using namespace std;
namespace A { int x = 5;}
namespace B { int x = 10;}

int main(){
    cout << "Hello Kotoha" << endl;
    cout << A::x << endl; // 名前空間Aのxを使用
    cout << B::x << endl; // 名前空間Bのxを使用

    int a,b;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "a+b=" << a + b << endl;

    return 0;
}
