#include <iostream>
using namespace std;

class Sample{
    public:
        void setNum(int num);
        int getNum();
    private:
        int private_num;
};

void Sample::setNum(int num){
    if (num >= 0) {          // 0以上であるかチェック
        private_num = num;
    } else {
        cout << "無効な値です。正の値を入力してください。" << endl;
        private_num = 0;     // 条件に合わない場合、安全なデフォルト値を設定
    }
}

int Sample::getNum(){
    return private_num;
}

int main(){
    Sample s;
    s.setNum(7);
    cout << s.getNum() << endl;
    s.setNum(-22);
    cout << s.getNum() << endl;
    return 0;
}