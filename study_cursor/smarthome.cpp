#include <iostream>
#include <cstdlib>
#include <ctime>
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
bool isGeneration = false;
bool isStorage = false;
bool isDistribution = false;

class SmartHome{
    public:
        SmartHome(string n) : name(n){}
    
    virtual void execute() = 0;  // 派生クラスで実装する    

    protected:
        string name;
};

// 充電
class Generation : public SmartHome{
    public:
        Generation(string n) : SmartHome(n){}
    
        void execute() override{
            cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
            cout << "    "  << name << " を開始します..." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "    " << name << " が完了しました！" << endl;
            NEWLINE;
        
        {
            lock_guard<mutex> lock(mtx);
            isGeneration = true;
        }
            cv.notify_one();
        }
};

class Storage : public SmartHome{
    public:
        Storage(string n) : SmartHome(n){}
    
    void execute() override{
        unique_lock<mutex> lock(mtx);
        while(isGeneration == false){
            cv.wait(lock);
        }

        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        isStorage = true;
        cv.notify_all();
    }
};

class Distribution : public SmartHome{
    public:
        Distribution(string n) : SmartHome(n){}

    void execute() override{
        unique_lock<mutex> lock(mtx);
        while(isStorage == false){
            cv.wait(lock);
        }

        cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
        cout << "    "  << name << " を開始します..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "    " << name << " が完了しました！" << endl;
        NEWLINE;

        isDistribution = true;
        cv.notify_all();
    }
};

class Monitoring : public SmartHome{
    private:
        int batteryLevel;
        Generation* generation;

    public:
        Monitoring(string n, int level, Generation* gen) 
        : SmartHome(n), batteryLevel(level), generation(gen){}
    
    // void execute() override{
    //     unique_lock<mutex> lock(mtx);
    //     while(isDistribution == false){
    //         cv.wait(lock);
    //     }
    //     cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    //     cout << "    " << name << " を開始します..." << endl;
    //     cout << "    現在のバッテリー残量: " << batteryLevel << "%" << endl;

    //     if (batteryLevel >= 50) {
    //         cout << "    状態: 通常運転モード" << endl;
    //     } else if(batteryLevel >= 20) {
    //         cout << "    状態: 省エネモードを有効化" << endl;
    //     } else {
    //         cout << "    状態: バッテリー残量が低すぎます！発電を再実行..." << endl;
    //         NEWLINE;

    //         isGeneration = false;

    //         // 新しいスレッドを立てて、再発電
    //         thread newGenThread(&Generation::execute, generation);
    //         newGenThread.join();
    //         {
    //             lock_guard<mutex> lock(mtx);
    //             isGeneration = true;  // 発電完了フラグを再度設定
    //         }
    //         cv.notify_all();

    //         batteryLevel = 50;
    //         cout << "    バッテリーが充電されました: " << batteryLevel << "%" << endl;
    //         // cout.flush();
    //     }

    //     cout << "    " << name << " が完了しました！" << endl;
    //     NEWLINE;
    // }
void execute() override{
    unique_lock<mutex> lock(mtx);
    while(isDistribution == false){
        cv.wait(lock);
    }
    cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "    " << name << " を開始します..." << endl;
    cout << "    現在のバッテリー残量: " << batteryLevel << "%" << endl;

    if (batteryLevel >= 50) {
        cout << "    状態: 通常運転モード" << endl;
    } else if(batteryLevel >= 20) {
        cout << "    状態: 省エネモードを有効化" << endl;
    } else {
        cout << "    状態: バッテリー残量が低すぎます！発電を再実行..." << endl;
        NEWLINE;

        isGeneration = false;

        cout << "    [DEBUG] 新しい発電スレッドを開始" << endl;
        thread newGenThread(&Generation::execute, generation);
        newGenThread.join();
        cout << "    [DEBUG] 発電スレッドがjoinされた" << endl;

        {
            lock_guard<mutex> lock(mtx);
            isGeneration = true;  // 発電完了フラグを再度設定
        }
        cv.notify_all();

        batteryLevel = 50;
        cout << "    バッテリーが充電されました: " << batteryLevel << "%" << endl;
        cout << "    状態: 通常運転モード" << endl;
    }

    cout << "    " << name << " が完了しました！" << endl;
    NEWLINE;
}



};

int main(){
    cout << "****このコードにはバグが含まれている****" << endl;
    cout << "⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "メインスレッド開始" << endl;
    NEWLINE;

    int batteryLevel = 0;
    srand(time(0));
    batteryLevel = rand() % 101;
    batteryLevel = 10;

    Generation generation("発電");
    Storage storage("蓄電");
    Distribution distribution("配電");
    Monitoring monitoring("監視", batteryLevel, &generation);

    thread subthread1(&Generation::execute, &generation);
    thread subthread2(&Storage::execute, &storage);
    thread subthread3(&Distribution::execute, &distribution);
    thread subthread4(&Monitoring::execute, &monitoring);

    subthread1.join();
    // cout << "サブスレッド終了" << endl;
    subthread2.join();
    // cout << "サブスレッド終了" << endl;
    subthread3.join();
    // cout << "サブスレッド終了" << endl;
    subthread4.join();
    cout << "サブスレッド終了" << endl;

    cout << "メインスレッド終了" << endl;
    NEWLINE;
}