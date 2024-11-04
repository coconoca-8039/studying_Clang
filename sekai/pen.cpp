#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Pen{
    public:
        Pen(string initColor);
        ~Pen();
        void write();
        int getInkLevel();
        string getColor();
    private:
        string color;
        int inkLevel;
};

Pen::Pen(string initColor) : color(initColor), inkLevel(100){
    cout << "Penクラスのインスタンスの生成" << endl;
    NEWLINE;
}

Pen::~Pen(){
    NEWLINE;
    cout << "Penクラスのインスタンスの消去" << endl;
}

void Pen::write(){
    inkLevel = inkLevel - 10;
    cout << "インク残量 : " << inkLevel << "で現在ライティング中です" << endl;
}

int Pen::getInkLevel(){
    return inkLevel;
}

string Pen::getColor(){
    return color;
}

int main(){
    Pen myPen("Red");
    cout << "color : " << myPen.getColor() << endl;
    myPen.write();
    myPen.write();
}