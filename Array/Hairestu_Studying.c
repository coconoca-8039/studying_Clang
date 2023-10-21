#include <stdio.h>

int main(void){
    printf("Kotoha\n");
    printf("kawaii\n");

    int num = 0;
    int box[num];  // 入れる数値を初期化しておかないとエラー出る
    printf("配列の個数は");
    scanf("%d", &num);
    int i;
    for(i = 0; i < 5; i++){
        box[i] = i +1;
    }
    for(i = 0; i < 5; i++){
        printf("box[%d]:%d\n", i, box[i]);
    }
    return 0;
}