#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // 配列のサイズ
#define MAX_VALUE 3 // 配列に入る一番大きい数

int main() {
    int array[SIZE] = {0};  // 配列を0で初期化
    int counter = 0;  // 書き込む値のカウンタ
    int count[MAX_VALUE] = {0};  // 各数字の出現回数を記録する配列
    bool all_same;

    while (1) {  // 無限ループ
        // 配列を右にスライドさせる  最後尾から更新しないとデータが上書きされてしまう
        for (int i = SIZE - 1; i > 0; i--) {
            array[i] = array[i - 1];
        }

        // 0～9のランダムな値を左端に挿入
        int random_value = rand() % MAX_VALUE;
        array[0] = random_value;
        printf("ランダム値: %d を挿入\n", random_value);

        printf("現在の配列: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // 各数字の個数を数える処理
        for (int i = 0; i < MAX_VALUE; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < SIZE; i++) {
            count[array[i]]++;  // 該当する数字のカウントを増やす
        }
        for (int i = 0; i < MAX_VALUE; i++) {
            if (count[i] > 0) {  // 配列内に存在する数字だけ表示
                printf("%d: %d個\n", i, count[i]);
            }
        }

        // 配列2個目以降が全て2の時
        all_same = true;  // フラグを true（真）で初期化
        for (int i = 1; i < SIZE; i++) {  // i = 1にしているのがポイント
            if (array[i] != 2) {
                all_same = false;
                break;
            }
        }
        if (all_same == true) {
            printf("\n");
            printf("222222222222222222222222222\n");
            printf("\n");
        }

        // 配列の0つ目と1つ目が1の時
        if(array[0] == 1 && array[1] == 1){
            printf("\n");
            printf("111111111111111111111111111\n");
            printf("\n");
        }

        printf("Press Enter...\n");
        getchar();
        
    }

    /*
    ランダム値: 2 を挿入
    現在の配列: 2 2 1 0 
    0: 1個
    1: 1個
    2: 2個
    Press Enter...
    */

    return 0;
}