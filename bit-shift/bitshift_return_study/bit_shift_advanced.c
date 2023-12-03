#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bitshift_header.h"
#define NEWLINE printf("\n");

int main(){
    uint64_t original_hex = 0xAB;   // 原型の16進数
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
}

