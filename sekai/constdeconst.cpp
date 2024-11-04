#include <iostream>
using namespace std;
#define NEWLINE std::cout << std::endl

class Car{
    public:
        Car();      // コンストラクタ
        ~Car();     // デコンストラクタ
        void setSpeed(double speed);    // スピードの設定
        double getSpeed();              // スピードの取得
        double getMigration();          // 移動距離の取得
        void drive(double hour);        // 走行
    
    private:
        double m_speed;     // 車速
        double m_migration; // 移動距離
};

Car::Car() : m_speed(0.0), m_migration(0.0){
    cout << "Carクラスのインスタンスの生成" << endl;
    NEWLINE;
}

Car::~Car(){
    NEWLINE;
    cout << "Carクラスのインスタンスの消去" << endl;
}

void Car::setSpeed(double speed){
    m_speed = speed;
}

double Car::getSpeed(){
    return m_speed;
}

double Car::getMigration(){
    return m_migration;
}

void Car::drive(double hour){
    cout << m_speed << "km/hで" << hour << "時間走行" << endl;
    cout << m_speed * hour << "km移動しました" << endl;
    m_migration += m_speed * hour;
}

int main(){
    Car tesla;
    tesla.setSpeed(100);
    tesla.drive(1.5);
    // tesla.setSpeed(50);
    // tesla.drive(2);
    cout << "移動距離 : " << tesla.getMigration() << "km" << endl;
    return 0;
}