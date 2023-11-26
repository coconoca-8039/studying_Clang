#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// プロトタイプ宣言
int hexToBinary(uint64_t hex);
uint64_t rightShift(uint64_t value, int shiftAmount);

int main(){
    // 右シフト
    uint64_t original_hex = 0xFF;   // 原型の16進数
    uint64_t right_shift_hex;       // 変換後の16進数
    uint64_t exchange_hex_to_bin; // 2進数

    // 元々の形
    NEWLINE;
    printf("オリジナルの10進数 : %llu\n", original_hex);  //10進数を表示
    printf("オリジナルの16進数 : %llX\n", original_hex);  //16進数を表示
    exchange_hex_to_bin = hexToBinary(original_hex);  //2進数を表示
    // 右シフト
    NEWLINE;
    right_shift_hex = rightShift(original_hex, 3);  // 右にシフト
    printf("右シフトをした10進数 : %llu\n", right_shift_hex);  //10進数を表示
    printf("右シフトをした16進数 : %llX\n", right_shift_hex);  //16進数を表示
    exchange_hex_to_bin = hexToBinary(right_shift_hex);  //2進数を表示

    // オリジナルの10進数 : 255
    // オリジナルの16進数 : FF
    // 0000 0000 0000 0000 0000 0000 1111 1111 

    // 右シフトをした10進数 : 31
    // 右シフトをした16進数 : 1F
    // 0000 0000 0000 0000 0000 0000 0001 1111 

}

uint64_t rightShift(uint64_t value, int shiftAmount){
    return value >> shiftAmount;
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