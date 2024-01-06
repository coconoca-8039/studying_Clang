#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define NEWLINE printf("\n");

// 2進数で数値を出力する関数
void printBinary(uint16_t num) {
    for (int i = 15; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    NEWLINE;
}

void printArray(uint8_t *candata){
    for(int i = 0; i <= 7; i++){
        printf("%02X ", candata[i]);
    }
}

int main(){
    // 宣言
    uint8_t candata[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  //配列
    uint8_t highByte, lowByte; // 上位8ビットと下位8ビットを格納する変数

    // 乱数の初期化
    srand(time(NULL));
    // ランダムな値を生成（0から65535まで）
    uint16_t data = rand() % 65536;

    printf("オリジナルの10進数 : %d\n", data);
    printf("オリジナルの16進数 : %02X\n", data);
    printf("オリジナルの2進数  : ");
    printBinary(data);
    printf("オリジナルの配列 \n");
    printArray(candata);
    NEWLINE;

    // 右シフト 上位8ビット
    // 0000001111111111 -> 000000000000011
    highByte = data >> 8;

    // ビットマスク 下位8ビット
    // 0000001111111111 -> 0000000011111111
    lowByte = data & 0xFF;  //

    // 代入
    candata[0] = lowByte;
    candata[1] = highByte;

    printf("Byte1とByte2に格納 \n");
    printArray(candata);
    NEWLINE;

    // 32ビットの乱数を生成
    uint32_t tmp = ((uint32_t)rand() << 16) | (uint32_t)rand();

    // ビットシフトとマスキングを使ってバイトを分割
    candata[4] = (tmp >> 24) & 0xFF;  // 最上位バイト
    candata[5] = (tmp >> 16) & 0xFF;  // 2番目のバイト
    candata[6] = (tmp >> 8) & 0xFF;   // 3番目のバイト
    candata[7] = tmp & 0xFF;          // 最下位バイト

    printf("Byte5から8に格納 \n");
    printArray(candata);
    NEWLINE;

}