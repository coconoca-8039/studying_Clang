#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Device{
    public:
        Device(string n) : name(n){}

    virtual void turnOn(){
        cout << name << ":デバイスが動作開始" << endl;
    }

    void setLED(){
        // 全てのLEDをOFFにする
        ledStatus = 0;
        cout << "すべてのLEDを消灯しました" << endl;
        displayStatus();
    }

    void setLED(uint8_t x){
        // LEDを一括で変更する
        ledStatus = x;
        cout << "セットその1" << endl;
        displayStatus();
    }

    void setLED(int ledNumber, int state){
        // 特定のLEDを点灯させる
        if(ledNumber < 1 || ledNumber > 8){
            cout << "入力エラー" << endl;
        }

        if(state == 1){
            ledStatus |= (1 << (ledNumber - 1));
        }

        cout << "セットその2" << endl;
        displayStatus();
    }

    void displayStatus(){
        cout << "現在のLED状態: " << bitset<8>(ledStatus) << endl;
        ledStatus = 0b00000000;  // 初期化しておく
        NEWLINE;
    }

    protected:
        string name;

    private:
        uint8_t ledStatus;
};

class LEDController : public Device{
    public:
        LEDController(string n) : Device(n){}
    
    void turnOn(){
        cout << name << ":LEDシステム起動" << endl;
    }
};

int main(){
    LEDController ledCtrl("RoomLight");
    ledCtrl.turnOn();
    ledCtrl.setLED();
    ledCtrl.setLED(0b01010011);
    // ledCtrl.setLED(0b0101);
    // ledCtrl.setLED(0b0000000011);
    ledCtrl.setLED(3,1);
    return 0;
}