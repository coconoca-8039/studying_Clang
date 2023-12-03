// #include <stdio.h>
// #include <stdint.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #define NEWLINE printf("\n");

// // プロトタイプ宣言
// uint64_t rightShift(uint64_t value, int shiftAmount);
// uint64_t leftShift(uint64_t value, int shiftAmount);
// int hexToBinary(uint64_t hex);
// void printBinary(uint8_t value);

// ビットマスク
uint64_t bitmask(uint64_t value, uint64_t mask) {
    // 論理積
    return value & mask;
}

// ビットセット
unsigned int setBitAtPosition(unsigned int value, int position) {
    // 1ビットを左に position 回シフト
    return value | (1U << position);
}

// ビットクリア
unsigned int clearBitAtPosition(unsigned int value, int position) {
    // ~はビット反転演算子
    // 0b00000000 が 0b11111111 になる
    return value & ~(1U << position);
}

// ビットトグル
unsigned int toggleBitAtPosition(unsigned int value, int position) {
    // ~はxor演算子
    return value ^ (1U << position);
}

uint64_t rightShift(uint64_t value, int shiftAmount){
    return value >> shiftAmount;
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

void printBinary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value & (1 << i)) ? 1 : 0);
        if (i == 4) {  // 4ビット目の後ろにスペースを挿入
            printf(" ");
        }
    }
    printf("\n");
}