#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

class CarThread {
public:
    CarThread(string n) : name(n), threadObj(&CarThread::run, this) {}

    ~CarThread() {
        if (threadObj.joinable()) {
            threadObj.join();  // スレッドの終了を待つ
        }
    }

    void run() {
        cout << name << "のスレッドが動作開始" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << name << "のスレッドが動作終了" << endl;
    }

private:
    string name;
    thread threadObj;  // スレッドオブジェクト
};

int main() {
    cout << "メインスレッド開始" << endl;
    CarThread myCar("BMW");
    cout << "メインスレッド終了" << endl;
    cout << "test" << endl;   
    return 0;
}
