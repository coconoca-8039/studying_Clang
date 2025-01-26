#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

mutex mtx;
condition_variable cv;
bool isReady = false;

// うどんを茹でる関数
void boil_udon(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "   うどんを茹でます" << endl;
    cout << "   うどんが茹で上がりました" << endl;
    NEWLINE;
}

// つゆを作る関数
void make_tuyu(){
    this_thread::sleep_for(chrono::seconds(2));
    cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "   出汁を取ります" << endl;
    cout << "   つゆが出来上がりました" << endl;
    NEWLINE;    
}

// 具材を準備する
void prepare_ingredient(){
    this_thread::sleep_for(chrono::seconds(3));
    cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "   具材を準備します" << endl;
    cout << "   具材が準備できました" << endl;
    NEWLINE;
}

// 盛り付けをする
void plating(){
    unique_lock<mutex> lock(mtx);
    while(!isReady){
        cv.wait(lock);  // cvは特定のスレッドが特定の条件を満たすまで待機するための仕組み   
    }   
    this_thread::sleep_for(chrono::seconds(1));
    cout << "   ⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "   盛り付けをします" << endl;
    cout << "   盛り付けが終わりました" << endl;
    NEWLINE;
}

int main(){
    unsigned int core_count = thread::hardware_concurrency();
    cout << "このPCで並列実行可能なスレッド数: " << core_count << endl;
    NEWLINE;

    // スレッドIDを取得
    cout << "⚫︎スレッド:" << this_thread::get_id() << endl;
    cout << "うどんを作ります" << endl;
    NEWLINE;

    // スレッドを作成 自動で開始される
    thread subthread1(boil_udon);
    thread subthread2(make_tuyu);
    thread subthread3(prepare_ingredient);
    thread subthread4(plating);

    // スレッドの終了を待つ 
    subthread1.join();
    subthread2.join();
    subthread3.join();

    {  // スコープを抜けるとロックが解放される  
        lock_guard<mutex> lock(mtx);
        isReady = true;
    }
    cv.notify_all();
    subthread4.join();  

    // スレッドを作成 自動で開始される
    cout << "うどんが完成しました" << endl;
    cout << "メインスレッド終了" << endl;
    return 0;
}