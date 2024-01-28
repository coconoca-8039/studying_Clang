#include <iostream>  // 外部の装置と入出力を行う機能を追加
#include <stdio.h>

// g++ sample.cppでコンパイルすることができる
// a.outという実行ファイルが作成される
// ./a.outで実行することができる

// g++ -o kotoha kihonnkoubunn.cpp && ./kotoha 
// g++ -O 作成される実行ファイル名 作成元のファイル名 && 実行したい操作

using namespace std;  // std空間を予め定義

int main(){
    std::cout << "ストリームを使用した出力" <<  std::endl;
    printf("printf関数を使用した出力\n");
    cout << "Kotoha" << endl;
    std::cout << "Flash" << std::endl;  // バッファを全て吐き出している
    std::cout << "backspace\n";
    cout << "Kotochan" << endl;
    cout << "kawaii" << endl;

    return 0;
}
