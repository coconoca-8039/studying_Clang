#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// プロトタイプ宣言
int hexToBinary(uint64_t hex);
uint64_t leftShift(uint64_t value, int shiftAmount);

int main(){
    // 左シフト
    uint64_t original_hex = 0xFF;   // 原型の16進数
    uint64_t left_shift_hex;       // 変換後の16進数
    uint64_t exchange_hex_to_bin; // 2進数

    // 元々の形
    NEWLINE;
    printf("オリジナルの10進数 : %llu\n", original_hex);  //10進数を表示
    printf("オリジナルの16進数 : %llX\n", original_hex);  //16進数を表示
    exchange_hex_to_bin = hexToBinary(original_hex);  //2進数を表示
    // 左シフト
    NEWLINE;
    left_shift_hex = leftShift(original_hex, 3);  // 右にシフト
    printf("右シフトをした10進数 : %llu\n", left_shift_hex);  //10進数を表示
    printf("右シフトをした16進数 : %llX\n", left_shift_hex);  //16進数を表示
    exchange_hex_to_bin = hexToBinary(left_shift_hex);  //2進数を表示

}

uint64_t leftShift(uint64_t value, int shiftAmount){
    return value << shiftAmount;
}

int hexToBinary(uint64_t hex){
    for (int i = 31; i >= 0; i--){
        if ((hex & (1 << i))){
            printf("1");
        }
        else{
            printf("0");
        }

        if (i % 4 == 0){ // 4ビットごとにスペースを挿入
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}