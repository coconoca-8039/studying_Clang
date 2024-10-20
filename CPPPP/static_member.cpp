#include <iostream>
#define NEWLINE std::cout << std::endl
using namespace std;

class Car {
public:
    // 静的メンバ変数: 全体の車の数を保持
    static int totalCars;
    // 通常のメンバ変数: 各車の名前
    string name;

    Car(const string& carName) : name(carName) {
        totalCars++;  // 静的メンバ変数をインクリメント（車が増えたことを記録）
        cout << name << " created. Total cars: " << totalCars << endl;
        NEWLINE;
    }

    ~Car() {
        totalCars--;
        cout << "Car " << name << " destroyed. Total cars: " << totalCars << endl;
        NEWLINE;
    }

    // 静的メンバ関数: 現在の車の総数を表示
    static void showTotalCars() {
        cout << "合計台数 : " << totalCars << endl;
        NEWLINE;
    }

    // 通常のメンバ関数: 車の名前を表示
    void showName() const {
        cout << "車の名前 : " << name << endl;
        NEWLINE;
    }
};

// 静的メンバ変数の初期化
int Car::totalCars = 0;

int main() {
    // 静的メンバ関数を使って初期状態の車の数を表示
    NEWLINE;
    Car::showTotalCars();

    {
        // 2つのCarオブジェクトを作成
        Car car1("Toyota");
        Car car2("Honda");
        Car car3("Nissan");

        // 各車の名前を表示
        car1.showName();
        car2.showName();
        car3.showName();

        // 静的メンバ関数を使って現在の車の総数を表示
        Car::showTotalCars();
    }  // car1 と car2 がスコープを抜けるとデストラクタが呼ばれる

    // スコープ外で静的メンバ関数を呼び出し、総数を確認
    Car::showTotalCars();

    return 0;
}