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
bool isCookingDone = false;
bool isPlatingDone = false;

class KitchenTask{
    public:
        KitchenTask(string n) : name(n){}
    
    virtual void execute() = 0;

    protected:
        string name;
};

class Cooking : public KitchenTask{
    public:
        Cooking(string n) : KitchenTask(n){}
    
    void execute() override {
        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        // 調理完了を通知
        {
            lock_guard<mutex> lock(mtx);
            isCookingDone = true;
        }
        cv.notify_all();
    }
};

class Plating : public KitchenTask{
    public:
        Plating(string n) : KitchenTask(n){}

    void execute() override {
        unique_lock<mutex> lock(mtx);
        while (!isCookingDone) {
            cv.wait(lock);  // 調理が終わるまで待機
        }

        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        // 盛り付け完了を通知
        isPlatingDone = true;
        cv.notify_all();
    }
};

class Washing : public KitchenTask{
    public:
        Washing(string n) : KitchenTask(n){}

    void execute() override {
        unique_lock<mutex> lock(mtx);
        while (!isPlatingDone) {
            cv.wait(lock);  // 盛り付けが終わるまで待機
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

    Cooking cook("調理");
    Plating plate("盛り付け");          
    Washing wash("洗い物");

    thread subthread1(&Cooking::execute, &cook);
    thread subthread2(&Plating::execute, &plate);
    thread subthread3(&Washing::execute, &wash);

    subthread1.join();
    subthread2.join();
    subthread3.join();

    cout << "メインスレッド終了" << endl;
    return 0;

}