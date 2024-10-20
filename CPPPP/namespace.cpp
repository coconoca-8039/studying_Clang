#include <iostream>

using namespace std;

namespace A{
    int power;
}

namespace B{
    int power;
}

void funcA();
void funcB();

int main(){
    A::power = 20;
    B::power = 30;
    cout << "main:power" << A::power << endl;
    cout << "main:power" << B::power << endl;
    funcA();
    funcB();
    return 0;
}

void funcA(){
    using namespace A;
    cout << "funcA:A::power=" << power << endl;
    cout << "funcA:B::power=" << B::power << endl;
    power = 40;
    cout << "namespace Aのpowerに40を代入" << endl;
}

void funcB(){
    using namespace B;
    cout << "funcA:A::power=" << A::power << endl;
    cout << "funcA:B::power=" << power << endl;
}
