#include <iostream>
#include <string>

using namespace std;

class Sample {
public:
    // コンストラクタ
    Sample(const std::string& name, int num) : m_name(name), m_num(num) {
        // コンストラクタ作成の時点で直接初期化されるためメモリ効率がいいらしい
        // m_name = name;
        // m_num = num;
        cout << "Sample object for " << m_name << " is created." << endl;
    }

    // デストラクタ
    ~Sample() {
        cout << "Sample object for " << m_name << " is destroyed." << endl;
    }

    // セッター: 数値を設定する
    void setNum(int num) {
        m_num = num;
    }

    // ゲッター: 数値を取得する
    int getNum() const {
        return m_num;
    }

    // 名前のゲッター
    std::string getName() const {
        return m_name;
    }

    // 定数メンバ関数：const修飾子があるため、値を変更しないことを保証
    void printInfo() const {
        cout << "Name: " << m_name << ", Num: " << m_num << endl;
    }

private:
    string m_name;  // 名前を保持
    int m_num;      // 数値を保持
};


class Example{
public:
    Example(const std::string& name, int num){
        // コンストラクタ作成の時点で直接初期化されるためメモリ効率がいいらしい
        m_name = name;
        m_num = num;
        cout << "Sample object for " << m_name << " is created." << endl;
    }

    // デストラクタ
    ~Example() {
        cout << "Sample object for " << m_name << " is destroyed." << endl;
    }

    void printInfo() const {
        cout << "Name: " << m_name << ", Num: " << m_num << endl;
    }

private:
    string m_name;  // 名前を保持
    int m_num;      // 数値を保持
};


int main() {
    // コンストラクタを使ってオブジェクトを生成
    cout << "~~~~~~~~~~~~~" << endl;
    Sample sample1("Sample1", 10);
    sample1.printInfo();
    sample1.setNum(20);
    sample1.printInfo();

    // 2つ目のオブジェクトを作成
    cout << "~~~~~~~~~~~~~" << endl;
    Sample sample2("Sample2", 50);
    sample2.printInfo();

    // 3つ目のオブジェクトを作成
    cout << "~~~~~~~~~~~~~" << endl;
    Sample kotoha("kotoha", 100);
    kotoha.printInfo();

    // プログラム終了時にデストラクタが呼ばれる
    cout << "~~~~~~~~~~~~~" << endl;

    Example tsushi("tsushi", 23);
    tsushi.printInfo();

    cout << "~~~~~~~~~~~~~" << endl;
    return 0;

    /*
    ~~~~~~~~~~~~~
    Sample object for Sample1 is created.
    Name: Sample1, Num: 10
    Name: Sample1, Num: 20
    ~~~~~~~~~~~~~
    Sample object for Sample2 is created.
    Name: Sample2, Num: 50
    ~~~~~~~~~~~~~
    Sample object for kotoha is created.
    Name: kotoha, Num: 100
    ~~~~~~~~~~~~~
    Sample object for kotoha is destroyed.
    Sample object for Sample2 is destroyed.
    Sample object for Sample1 is destroyed.
    */
}