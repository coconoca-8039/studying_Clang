#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <string>
#include <functional> 
using namespace std;
#define NEWLINE std::cout << std::endl

mutex mtx;
condition_variable cv;
bool isReady = false;

class Car{
    public:
        Car(string n) : name(n){}
    
    void startEngine(){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    " << name << "   エンジン始動" << endl;
        NEWLINE;
    }

    void playMusic(){
        this_thread::sleep_for(chrono::seconds(2));
        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    " << name << "   音楽再生" << endl;
        NEWLINE;
    }

    void drive(){
        unique_lock<mutex> lock(mtx);
        while(!isReady){
            cv.wait(lock);
        } 
        this_thread::sleep_for(chrono::seconds(1));
        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    " << name << "   運転開始" << endl;
        NEWLINE;
    }

    protected:
        string name;
};

class BMW : public Car{
    public:
        BMW(string n) : Car(n){}
};

int main(){
    unsigned int core_count = thread::hardware_concurrency();
    cout << "このPCで並列実行可能なスレッド数: " << core_count << endl;
    NEWLINE;

    cout << "⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "メインスレッド開始" << endl;
    NEWLINE;

    BMW car1("BMW");
    // car1.startEngine();
    // car1.playMusic();
    // car1.drive();   

    thread subthread1(&Car::startEngine, &car1);
    thread subthread2(&Car::playMusic, &car1);
    thread subthread3(&Car::drive, &car1);
    // thread subthread1(&Car::startEngine, std::ref(car1));
    // thread subthread2(&Car::playMusic, std::ref(car1));
    // thread subthread3(&Car::drive, std::ref(car1));
    // thread subthread1([&car1]() { car1.startEngine(); });
    // thread subthread2([&car1]() { car1.playMusic(); });
    // thread subthread3([&car1]() { car1.drive(); });
    // Car* carPtr = &car1;
    // thread subthread1(&Car::startEngine, carPtr);
    // thread subthread2(&Car::playMusic, carPtr);
    // thread subthread3(&Car::drive, carPtr);
    // thread subthread1([&car1]() { car1.startEngine(); });
    // thread subthread2([&car1]() { car1.playMusic(); });
    // thread subthread3([&car1]() { car1.drive(); }); 
    // thread subthread1(&Car::startEngine, std::ref(car1), std::ref(car1));
    // thread subthread2(&Car::playMusic, std::ref(car1), std::ref(car1));
    // thread subthread3(&Car::drive, std::ref(car1), std::ref(car1)); 

    subthread1.join();
    subthread2.join();
    {  
        lock_guard<mutex> lock(mtx);
        isReady = true;
    }
    cv.notify_all();
    subthread3.join(); 
    
    cout << "メインスレッド終了" << endl;
    return 0;   
}