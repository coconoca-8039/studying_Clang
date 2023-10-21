#include <stdio.h>
#include <stdint.h>

// ビットマスクと組み合わせ
// ビットセット
// ビットクリア
// ビットトグル
// ローテート

uint8_t hexToBinary(uint32_t hex){
    for (int i = 7; i >= 0; i--){
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

uint8_t rightShift(uint8_t value, int shiftAmount){
    return value >> shiftAmount;
}

uint8_t leftShift(uint8_t value, int shiftAmount){
    return value << shiftAmount;
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

// ビットマスク処理関数
uint8_t bitmask(uint8_t value, uint8_t mask) {
    return value & mask;  // 論理積
}

// ビットセット処理関数
// 指定したビット位置をセットする関数
    uint8_t setBitAtPosition(uint8_t value, int position) {
    if (position < 0 || position > 7) { // 0~7以外はエラーにするだけ
        return value;
    }
    uint8_t mask;  // 0000 0000 
    mask = 1 << position; // 指定したビット位置だけが1 左シフト
    return value | mask;  // 論理和・・・指定したビット位置をセット
}

// ビットクリア処理関数
// 指定したビット位置をクリアする関数
uint8_t clearBitAtPosition(uint8_t value, int position) {
    if (position < 0 || position > 7) { // 位置が範囲外の場合、元の値をそのまま返す
        return value;
    }
    uint8_t mask;
    mask = ~(1 << position); // 指定したビット位置だけが0（他は1） ~はビット反転の演算子
    return value & mask;  // 論理積を使って指定したビット位置をクリア
}

// ビットトグル処理関数
// 2つの入力のうち、1つだけが1であるときに1を出力し、それ以外は0を出力する
uint8_t toggleBitAtPosition(uint8_t value, int position) {
    if (position < 0 || position > 7) { // 位置が範囲外の場合、元の値をそのまま返す
        return value;
    }
    uint8_t mask;
    mask = 1 << position; // 指定したビット位置だけが1
    return value ^ mask;  // XORを使って指定したビット位置をトグル
}

int main(){

    // ビットマスク
    // 1が立っている部分のみをコピーして、他は0を入れる
    printf("ビットマスク\n");
    uint8_t value = 0b10101010;
    printf("マスク前:");
    printBinary(value);
    uint8_t mask  = 0b11110000;
    uint8_t result = bitmask(value, mask);
    printf("マスク後:");
    result = hexToBinary(result);
    // マスク前:1010 1010
    // マスク後:1010 0000

    // ビットセット
    // 特定の位置のビットに1をセットする
    printf("ビットセット\n");
    uint8_t val = 0b00000000;
    printf("Before: %02X\n", val);
    val = setBitAtPosition(val, 3);  //0000 1000
    printf("After : %02X\n", val);
    // Before: 00
    // After : 08

    // ビットクリア
    // 特定の位置のビットに0をセットする
    printf("ビットクリア\n");
    uint8_t val_clear = 0b11111111; // 全てのビットが1
    printf("Before: ");
    printBinary(val_clear);
    val_clear = clearBitAtPosition(val_clear, 3);  // 3番目のビットをクリア: 1111 0111
    val_clear = clearBitAtPosition(val_clear, 2);  // 2番目のビットをクリア: 1111 0011
    printf("After : ");
    printBinary(val_clear);
    // Before: 1111 1111
    // After : 1111 0011

    //ビットトグル
    printf("ビットトグル\n");
    uint8_t val_toggle = 0b11110000;
    printf("Before: ");
    printBinary(val_toggle);
    val_toggle = toggleBitAtPosition(val_toggle, 4);  // 0001 0000
    printf("After : ");
    printBinary(val_toggle);
    // Before: 1111 0000
    // After : 1110 0000

    return 0;
}