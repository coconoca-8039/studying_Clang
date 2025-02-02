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
bool isProcessingDone = false;
bool isAssemblingDone = false;

// 基本クラス
class FactoryTask{
    public:
        FactoryTask(string n) : name(n){}
    
    virtual void execute() = 0;  // 派生クラスで実装する    

    protected:
        string name;
};

// 派生クラス
class Processing : public FactoryTask{
    public:
        Processing(string n) : FactoryTask(n){} 

    void execute() override {
        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        {
            lock_guard<mutex> lock(mtx);
            isProcessingDone = true;
        }
        cv.notify_all();
    }
};

class Assembling : public FactoryTask{
    public:
        Assembling(string n) : FactoryTask(n){} 
    
    void execute() override {
        unique_lock<mutex> lock(mtx);
        while (isProcessingDone == false) {
            cv.wait(lock);  // 調理が終わるまで待機
        }

        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        // 加工完了を通知
        isAssemblingDone = true;
        cv.notify_all();
    };
    
};

class Inspection : public FactoryTask{
    public:
        Inspection(string n) : FactoryTask(n){} 
    
    void execute() override{
        unique_lock<mutex> lock(mtx);

        while (isAssemblingDone == false) {  // ここでちゃんとチェックする
            cv.wait(lock);
        }

        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;
    }
};

int main(){
    cout << "⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "メインスレッド開始" << endl;
    NEWLINE;

    Processing p("加工");
    Assembling a("組み立て");
    Inspection i("検査");

    thread t1(&Processing::execute, &p);
    thread t2(&Assembling::execute, &a);
    thread t3(&Inspection::execute, &i);

    t1.join();
    t2.join();
    t3.join();

    cout << "メインスレッド終了" << endl;
    return 0;

}