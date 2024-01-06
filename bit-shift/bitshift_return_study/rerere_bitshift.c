#include <stdio.h>
#include <stdint.h>

#define NEWLINE printf("\n");

// 2進数で数値を出力する関数
void printBinary(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    NEWLINE;
}

int main(){
    uint8_t num = 0xFF;
    printf("オリジナルの16進数 : %02X\n", num);
    printf("オリジナルの2進数  : ");
    printBinary(num);
    NEWLINE;

    // 左シフト
    uint8_t leftShifted = num << 1;
    printf("左シフトの16進数 : 0x%02X -> 0x%02X\n", num, leftShifted);
    printf("左シフトの2進数  : ");
    printBinary(leftShifted);
    NEWLINE;

    // 右シフト
    uint8_t rightShifted = num >> 1;
    printf("右シフトの16進数 : 0x%02X -> 0x%02X\n", num, rightShifted);
    printf("右シフトの2進数  : ");
    printBinary(rightShifted);
    NEWLINE;

    オリジナルの16進数 : FF
    // オリジナルの2進数  : 11111111

    // 左シフトの16進数 : 0xFF -> 0xFE
    // 左シフトの2進数  : 11111110

    // 右シフトの16進数 : 0xFF -> 0x7F
    // 右シフトの2進数  : 01111111
}