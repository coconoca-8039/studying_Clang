#include <iostream>
#include <memory>        // std::unique_ptr
#include <thread>        // std::thread
#include <mutex>         // std::mutex, std::lock_guard
#include <chrono>        // std::this_thread::sleep_for
#include <bitset>        // std::bitset（ビット演算の可視化）
#include <type_traits>   // std::enable_if, std::is_integral

using namespace std;
mutex mtx;

class Sensor{
    private:
        int sensorID;
        int data;

    public:
        // explicitっで暗黙の型変換を禁止させる　今回はintで固定
        explicit Sensor(int id) : sensorID(id), data(0){}

    // デストラクタ
    virtual ~Sensor(){}

    // センサーの値を取得するための関数
    void fetchData(){
        // lock_guard<mutex> lock(mtx);
        data = rand() % 101;
    }

    // dataの値を取得するための関数
    int getData() const{return data;}
};

class Processor{
    private:
        unique_ptr<Sensor> sensor1;
        thread sensorThread;
        bool running;

    public:
        explicit Processor(int senserID)
        : sensor1(make_unique<Sensor>(senserID)), running(true){
        sensorThread = thread(&Processor::monitor, this);
        }

    ~Processor(){
    running = false;  
    // this_thread::sleep_for(chrono::milliseconds(100)); 
    if (sensorThread.joinable()) { 
        sensorThread.join();
    }
}

    void monitor(){
        while(running == true){
            {
                lock_guard<mutex> lock(mtx);
                sensor1->fetchData();
                int value = sensor1->getData();
                std::cout << "[Sensor1] データ取得!!: " << value << std::endl;
                
                if(value >= 80){
                    cout << "⚠ アラート！異常値 " << value << " が検出!" << endl;
                }
            }
            // 一定時間待機
            this_thread::sleep_for(chrono::seconds(1));
            // for (int i = 0; i < 10; i++) { 
            //     if (!running) return;
            //     this_thread::sleep_for(chrono::milliseconds(100));
            // }
        }
    }

};

int main(){
    // 乱数シードの作成
    srand(time(nullptr));

    // センサーID 1 の Processor を作成
     Processor processor(1);  

    // しばらく動作させる（10秒）
    this_thread::sleep_for(chrono::seconds(10));

    return 0;
}