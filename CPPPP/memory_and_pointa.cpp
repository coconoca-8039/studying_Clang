#include <iostream>

using namespace std;

int main(){
    int a = 100;
    cout << "aの値の大きさは?" << a;
    cout << "大きさは" << sizeof(int) << "byte" << endl;
    cout << "アドレスは" << std::hex << &a << "です" << endl;

    return 0;
}