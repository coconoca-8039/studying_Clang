#include <iostream>
#include <memory>        // std::unique_ptr
#include <thread>        // std::thread
#include <mutex>         // std::mutex, std::lock_guard
#include <chrono>        // std::this_thread::sleep_for
#include <bitset>        // std::bitset（ビット演算の可視化）
#include <type_traits>   // std::enable_if, std::is_integral

using namespace std;
mutex mtx;

class Sensor {
    private:
        int sensorID;
        int data;

    public:
        explicit Sensor(int id) : sensorID(id), data(0){}
    
    virtual ~Sensor(){}

    void fetchData(){
        lock_guard<mutex> lock(mtx);
        data = rand() % 256;
        cout << "[Sensor " << sensorID << "] New Data: " << 
        bitset<8>(data) << " (" << data << ")" << endl;
    }

    // dataの値を取得するための関数
    int getData() const { return data; }
};

// テンプレートを使って、型Tを後から決められるようにする
template <typename T>
// enable_if を使って、T が整数型（int, short, long など）の場合のみ関数を有効にする
typename enable_if<is_integral<T>::value, T>::type
processData(T value) {  // 関数名を追加
    lock_guard<mutex> lock(mtx);
    cout << "[Processing] Raw Data: " << bitset<8>(value) << " (" << value << ")" << endl;
    
    // ビット演算でデータ加工
    value = (value << 2) & 0xFF;  // 左シフト2回 & 8ビットマスク
    cout << "[Processing] Shifted:  " << bitset<8>(value) << " (" << value << ")" << endl;
    
    value = value ^ 0b10101010;   // XOR でパターン変更
    cout << "[Processing] XORed:   " << bitset<8>(value) << " (" << value << ")" << endl;

    return value;
}

int main(){
    // 乱数生成
    srand(time(nullptr));

    // センサーオブジェクトをスマートポインタで管理
    unique_ptr<Sensor> sensor = make_unique<Sensor>(1);

    // センサーデータ取得スレッド
    thread sensorThread([&]() {
        for (int i = 0; i < 3; ++i) {
            this_thread::sleep_for(chrono::milliseconds(500));
            sensor->fetchData();
        }
    });

    thread processingThread([&](){
        this_thread::sleep_for(chrono::milliseconds(700));
        int data = sensor->getData();
        processData(data);
    });

    sensorThread.join();
    processingThread.join();

    cout << "Program Finished." << endl;
    return 0;

}