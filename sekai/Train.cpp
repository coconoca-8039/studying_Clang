#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

template<typename T>

class Vehicle{
    public:
        Vehicle(T ve_name) : name(ve_name){}

    virtual void move(){
        cout << name << "が移動" << endl;
    }

    protected:
        T name;
};

class Train : public Vehicle<string>{
    public:
        Train(string ve_name, int ve_speed, int ve_distance) : Vehicle(ve_name), speed(ve_speed), distance(ve_distance){}

    void move() override{
        cout << name << "が線路を移動" << endl;
    }

    void move(int speed, int distance){
        cout << name << "が" << speed << "km/hで" << distance << "km移動" << endl;    
    }

    private:
        int speed;
        int distance;
};

int main(){
    Vehicle<string> Densya("電車");
    Densya.move();
    NEWLINE;

    Train Hakutaka("はくたか", 0, 0);
    Hakutaka.move();
    Hakutaka.move(200, 400);
}