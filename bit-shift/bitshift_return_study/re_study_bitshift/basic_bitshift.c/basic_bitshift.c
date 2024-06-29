#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

/*
今回の目的
ビットシフト、ビットセット、ビットマスク、ビットクリア、ビットトグル、分割
を勉強していく
*/

// プロトタイプ宣言
uint64_t rightShift(uint64_t value, int shiftAmount);
uint64_t leftShift(uint64_t value, int shiftAmount);
int hexToBinary(uint64_t hex);
void printBinary(uint8_t value);
uint16_t setBit(uint16_t value, int bitPosition);
uint16_t clearBit(uint16_t value, int bitPosition);
uint16_t maskBits(uint16_t value, uint16_t mask);

uint64_t rightShift(uint64_t value, int shiftAmount){
    return value >> shiftAmount;
}

uint64_t leftShift(uint64_t value, int shiftAmount){
    return value << shiftAmount;
}

uint16_t setBit(uint16_t value, int bitPosition){
    return value | (1 << bitPosition);  // OR演算
    // 対応するビットのどちらかが1であれば1を返す演算
}

uint16_t clearBit(uint16_t value, int bitPosition){
    return value & ~(1 << bitPosition);  // AND演算
    // 対応するビットの両方が1である場合に1を返す演算
}

uint16_t maskBits(uint16_t value, uint16_t mask){
    return value & mask;  //AND演算で比較している
    /*
    ビットマスクの用途
    ビットの抽出: 特定のビットだけを取り出す
    ビットの設定: 特定のビットを1にする
    ビットのクリア: 特定のビットを0にする
    ビットのトグル: 特定のビットの状態を反転する
    */
}

int hexToBinary(uint64_t hex){
    for (int i = 15; i >= 0; i--){
        if ((hex & (1 << i))){  // // 16進数の値と、1を左にiビットシフトした値をAND演算
            printf("1");
        }
        else{
            printf("0");
        }
        if (i % 4 == 0){ // 4ビットごとにスペースを挿入
            printf(" ");
        }
    }
    NEWLINE;
    return 0;
}

int main(){
    // 左シフト
    NEWLINE;
    uint64_t original_hex = 0x04;   // 原型の16進数
    uint64_t left_shift_hex;       // 変換後の16進数
    uint64_t exchanger;
    uint64_t mask = 0xABCD;   // 1010 1011 1100 1101
    uint64_t value = 0x0F0F;  // 0000 1111 0000 1111

    printf("オリジナルの10進数 : %llu\n", original_hex);  //10進数を表示
    printf("オリジナルの16進数 : %llX\n", original_hex);  //16進数を表示
    NEWLINE;
    printf("オリジナル：");
    hexToBinary(original_hex);  //2進数を表示

    NEWLINE;
    exchanger = rightShift(original_hex, 1);
    printf("右シフト : %llu\n", exchanger);     
    hexToBinary(exchanger);                 // 0000 0010

    NEWLINE;
    exchanger = leftShift(original_hex, 1);
    printf("左シフト : %llu\n", exchanger);     
    hexToBinary(exchanger);                 // 0000 1000

    NEWLINE;
    exchanger = setBit(original_hex, 1);
    printf("ビットセット : %llu\n", exchanger);
    hexToBinary(exchanger);                 // 0000 0110

    NEWLINE;
    exchanger = clearBit(original_hex, 2);
    printf("ビットクリア : %llu\n", exchanger);
    hexToBinary(exchanger);                 // 0000 0000

    NEWLINE;
    exchanger = maskBits(value, mask);
    printf("マスクされる値\n");
    hexToBinary(value);
    printf("マスクする値\n");
    hexToBinary(mask);
    // printf("ビットマスク : %llu\n", exchanger);
    printf("マスク後\n");
    hexToBinary(exchanger);                 // 0000 1010

}