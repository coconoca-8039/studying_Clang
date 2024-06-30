#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

int linerSearch(int arr[], int n, int target){
    // 引数(配列, 配列サイズ, 探したい値)
    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    /************************************/
    // 配列の基本
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    printf("配列のサイズ: %d\n", size);
    NEWLINE;

    for (int i = 0; i < 5; i++){
        printf("%d\n", numbers[i]);
    }
    NEWLINE;

    for (int i = size - 1;i >= 0; i--){
        printf("%d ", numbers[i]);
        if (i == 0){
            NEWLINE;
        }
    }
    NEWLINE;

    /************************************/
    // 二次元配列
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    // 配列全体のサイズを1行分のサイズで割る
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    // 1行分のサイズを1要素分のサイズで割る

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", matrix[i][j]);
        }
        NEWLINE;
    }
    printf("行数: %d, 列数: %d\n", rows, cols);
    NEWLINE;

    /************************************/
    // 三次元配列
    int tensor[2][3][4] = {
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}},
    {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}}
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%d ", tensor[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    /************************************/
    // 配列の初期化
    int zero[1][2] = {0};
    
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 2; j++){
            printf("zero[%d][%d] = %d\n", i, j, zero[i][j]);
        }
    }
    NEWLINE;

    /************************************/
    // 線形探索
    int nums_linerSearch[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size_liner = sizeof(nums_linerSearch) / sizeof(nums_linerSearch[0]);
    int target = 7;
    int index = linerSearch(nums_linerSearch, size_liner, target);

    for (int i = 0; i < size_liner; i++){
        printf("%d ", nums_linerSearch[i]);
    }
    NEWLINE;

    if (index != -1){
        printf("要素 %d はインデックス %d にあります。\n", target, index);
    }else{
        printf("要素 %d は見つかりませんでした。\n", target);
    }
    NEWLINE;

    /************************************/
    // 動的配列
    /*
    malloc関数
    mallocは動的にメモリを割り当てるための関数
    指定されたバイト数のメモリをヒープ領域から割り当てる
    */
    // 動的配列の割り当て
    int *arr;
    int size_adj = 5;
    arr = (int *)malloc(size_adj * sizeof(int));
    if (arr == NULL){
        printf("メモリの割り当てに失敗しました\n");
        return 1;
    }
    
    // 配列の初期化と表示
    for (int i = 0; i < size_adj; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    /*
    realloc関数
    既に動的に割り当てられたメモリを再割り当てするための関数
    既存のメモリブロックのサイズを変更する
    */
    // 配列サイズの変更
    size_adj = 10;
    arr = (int * )realloc(arr, size_adj * sizeof(int));
    if (arr == NULL){
        printf("メモリの割り当てに失敗しました\n");
        return 1;
    }

    for (int i = 0; i < size_adj; i++) {
        arr[i] = i + 1;
    }
    for (int i = 5; i < size_adj; i++){
        printf("%d ", arr[i]);
    }
    NEWLINE;
    NEWLINE;

    // メモリの解放
    free(arr);

    /************************************/
    // 配列の中身を任意で変更する
    int static_array[5] = {1, 2, 3, 4, 5};
    
    // オリジナルの配列
    printf("オリジナルの配列\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", static_array[i]);
    }
    NEWLINE;

    // 配列の要素を変更
    static_array[1] = 10;  // 2番目の要素を10に変更
    static_array[3] = 20;  // 4番目の要素を20に変更
    printf("配列の要素を変更\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", static_array[i]);
    }
    NEWLINE;

    return 0;
}