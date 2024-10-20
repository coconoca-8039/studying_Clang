#ifndef _CAR_134_H_
#define _CAR_134_H_

class Car{
public:
    // コンストラクタ
    Car();
    // デストラクタ
    ~Car();
    // スピードの設定
    void setSpeed(double speed);
    // スピードの取得
    double getSpeed();
    double getMigration();
    // 走行する
    void drive(double hour);

private:
    double m_speed;
    double m_migration;

};
#endif