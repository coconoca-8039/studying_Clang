#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Appliance{
    public:
        Appliance(string n) : name(n){}
    
    virtual void turnOn(){
        cout << name << "電源ON" << endl;
    }

    void setPower(int w){
        wat = w;
        cout << name << "パワーを" << w << "ワットに設定" << endl;
    }

    void setPower(int w, int x){
        wat = w;
        string mode = "Normal";

        switch (x){
        case 1:
            mode = "Normal";
            break;
        case 2:
            mode = "Powerful";
            break;
        default:
            mode = "Broken";
            break;
        }

        cout << name << "パワーを" << w << "ワットに設定" << endl;
        cout << "選択モード：" << mode << endl;
    }

    protected:
        string name;
        int wat;
};

class WashingMachine : public Appliance{
    public:
        WashingMachine(string n) : Appliance(n){}
};

int main(){
    WashingMachine wm("AQUA");
    wm.turnOn();
    wm.setPower(500);
    wm.setPower(200,1);
}