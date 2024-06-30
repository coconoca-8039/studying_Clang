#include <stdio.h>
#include <stdint.h>
#define NEWLINE printf("\n");

// ビットシフトのマクロ定義
#define LEFT_SHIFT(value, shift) ((value) << (shift))
#define RIGHT_SHIFT(value, shift) ((value) >> (shift))
#define SET_BIT(value, bit) ((value) |= (1 << (bit)))
#define CLEAR_BIT(value, bit) ((value) &= ~(1 << (bit)))
#define TOGGLE_BIT(value, bit) ((value) ^= (1 << (bit)))
#define MASK_BITS(value, mask) ((value) & (mask))

// 進数変換
int hexToBinary(uint64_t hex){
    for (int i = 7; i >= 0; i--){
        if ((hex & (1 << i))){printf("1");}
        else{printf("0");}
        if (i % 4 == 0){ printf(" ");}}
    NEWLINE;
    return 0;
}

// パリティビットを計算する関数
int calculate_parity(uint32_t value) {
    value ^= value >> 16;
    value ^= value >> 8;
    value ^= value >> 4;
    value ^= value >> 2;
    value ^= value >> 1;
    return value & 1;  // 最下位ビットがパリティビット
}

// 左回転シフト
uint32_t rotate_left(uint32_t value, int shift) {
    int bits;
    bits = sizeof(value) * 8;  // データ型のビット幅を取得
    return (value << shift) | (value >> (bits - shift));
}

// 右回転シフト
uint32_t rotate_right(uint8_t value, int shift) {
    int bits;
    bits = sizeof(value) * 8;  // データ型のビット幅を取得
    return (value >> shift) | (value << (bits - shift));
}

int main() {
    uint32_t value = 0x02;
    int parity;

    parity = calculate_parity(value);
    printf("値: 0x%X\n", value);
    hexToBinary(value);
    printf("パリティビット: %d\n", parity);
    // 0000 0000 -> 1 奇数

    NEWLINE;
    value = 0x03;
    parity = calculate_parity(value);
    printf("値: 0x%X\n", value);
    hexToBinary(value);
    printf("パリティビット: %d\n", parity);
    // 0000 0011 -> 0 偶数

    /************************************/
    NEWLINE;
    uint8_t rotated_value = 0x0F;

    uint8_t left_rotated = rotate_left(rotated_value, 1);
    uint8_t right_rotated = rotate_right(rotated_value, 1);

    printf("元の値: 0x%X\n", rotated_value);
    hexToBinary(rotated_value);
    printf("左回転シフト: 0x%X\n", left_rotated);
    hexToBinary(left_rotated);
    printf("右回転シフト: 0x%X\n", right_rotated);
    hexToBinary(right_rotated);

    return 0;
}