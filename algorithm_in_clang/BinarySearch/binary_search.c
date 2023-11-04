#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// 二分探索

int bi_search(int array2[], int num2, int ans2){
    int first = 0;          // 探索範囲の最初を示す
    int last = num2 - 1;    // 探索範囲の最後を示す
    do{
        int center = (first + last) / 2;    // 配列の真ん中を探す

        if(array2[center] == ans2){
            return center;                  // 真ん中の値がans2と一致していたらハッピーエンド
        }
        else if(array2[center] < ans2){     // 真ん中の要素が探している値より小さかったら
            first = center + 1;             // 探索範囲を後半部に絞る
        }else{
            last = center - 1;              // 探索範囲を前半部に絞る
        }
    }while(first <= last);                  // 探索が終わるまで繰り返す
    
    return -1;                              // 探している値がなかったら-1を返す
}

int main(void){
    int num = 0;
    int ans = 0;
    printf("配列の要素数は\n");
    scanf("%d", &num);
    int array[num];
    int i;
    
    printf("小さい値から入力してください\n");
    printf("1番目 : ");
    scanf("%d", &array[0]);  // ここで1番目に数字を入れる　この値が起点で大きい値を入れていく
    for(i = 1; i < num; i++){
        do{
        printf("%d番目 : ", i + 1);
        scanf("%d", &array[i]);
        }while(array[i] < array[i-1]);  // 小さい値を入れたらやり直し
    }

    printf("探す数は?");
    scanf("%d", &ans);
    
    int result = bi_search(array, num, ans);
    if(result == -1){
        printf("失敗です\n");
    }else{
        printf("%dは%d番目にありました\n", ans, result + 1);
    }
    return 0;
}
