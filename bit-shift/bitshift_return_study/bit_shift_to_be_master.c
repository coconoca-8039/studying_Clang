#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// プロトタイプ宣言
uint64_t rightShift(uint64_t value, int shiftAmount);
uint64_t leftShift(uint64_t value, int shiftAmount);
int hexToBinary(uint64_t hex);
void printBinary(uint8_t value);

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

/********************************************************************/
int main(){
    // ビットマスク
    // 特定のビットだけを取り出す操作
    // 1が立っている部分のみをコピーして、他は0を入れる
    // 大きい値を2byte以上に代入する時に使用することよ
    printf("ビットマスク\n");
    uint8_t value = 0b01010101;
    uint8_t mask  = 0b11110000;
    uint8_t result = bitmask(value, mask);
    printf("マスク前: ");
    printBinary(value);  // マスク前: 0101 0101
    printf("マスク後: ");
    printBinary(result);  // マスク後: 0101 000
    NEWLINE;

    // ビットセット
    // 特定のビットに1をセットする操作
    printf("ビットセット\n");
    uint8_t value_bitset = 0b01010000;
    uint8_t result_bitset;
    result_bitset = setBitAtPosition(value_bitset, 0);  // 1bit目に1を入れる
    result_bitset = setBitAtPosition(result_bitset, 1);  // 2bit目に1を入れる
    printf("ビットセット前: ");
    printBinary(value_bitset);  // ビットセット前: 0101 0000
    printf("ビットセット後: ");
    printBinary(result_bitset);  // ビットセット後: 0101 0011
    NEWLINE;

    // ビットクリア
    // 特定のビットを0にする操作
    printf("ビットクリア\n");
    uint8_t value_bitclear = 0b01011111;
    uint8_t result_bitclear;
    result_bitclear = clearBitAtPosition(value_bitclear, 0);
    result_bitclear = clearBitAtPosition(result_bitclear, 1);
    printf("ビットクリア前: ");
    printBinary(value_bitclear);  // ビットクリア前: 0101 1111
    printf("ビットクリア後: ");
    printBinary(result_bitclear);  // ビットクリア後: 0101 1100
    NEWLINE;

    // ビットトグル
    // 特定のビットを反転させる操作
    printf("ビットトグル\n");
    uint8_t value_bittoggle = 0b01010011;
    uint8_t result_bittoggle;
    result_bittoggle = toggleBitAtPosition(value_bittoggle, 0);
    result_bittoggle = toggleBitAtPosition(result_bittoggle, 1);
    result_bittoggle = toggleBitAtPosition(result_bittoggle, 2);
    result_bittoggle = toggleBitAtPosition(result_bittoggle, 3);
    printf("反転前: ");
    printBinary(value_bittoggle);  // 01010011
    printf("反転後: ");
    printBinary(result_bittoggle);  // 01011100

}


/********************************************************************/
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