#include "car134.h"
#include <iostream>
using namespace std;

Car::Car() : m_speed(0.0), m_migration(0.0){
    cout << "Carクラスのインスタンスの生成" << endl;
}

Car::~Car(){
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