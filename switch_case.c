#include <stdio.h>

int main(){

    int no;
    no = 2;

    // switch-caseは整数でしか分岐できない
    switch (no){
    case 1:
        // braeakを書かなければ、続けてcase2に移行できる
        // フォールスルーという
    case 2:
        printf("kotoha\n");
        break;
    case 3:
        printf("hanon\n");
        break;
    default:
        break;
    }
    return 0;
}