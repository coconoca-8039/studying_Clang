#ifndef _CAR134_H_
#define _CAR134_H_

class Car{
    public:
        Car();      // コンストラクタ
        ~Car();     // デコンストラクタ
        void setSpeed(double speed);    // スピードの設定
        double getSpeed();              // スピードの取得
        double getMigration();          // 移動距離の取得
        void drive(double hour);        // 走行する
    
    private:
        double m_speed;     // 車速
        double m_migration; // 移動距離
};

#endif