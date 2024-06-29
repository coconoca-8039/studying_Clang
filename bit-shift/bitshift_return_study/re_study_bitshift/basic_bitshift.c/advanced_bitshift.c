#include <stdio.h>
#include <stdint.h>

// ビットシフトのマクロ定義
#define LEFT_SHIFT(value, shift) ((value) << (shift))
#define RIGHT_SHIFT(value, shift) ((value) >> (shift))

// ビットセット、ビットクリア、ビットトグルのマクロ
#define SET_BIT(value, bit) ((value) |= (1 << (bit)))
#define CLEAR_BIT(value, bit) ((value) &= ~(1 << (bit)))
#define TOGGLE_BIT(value, bit) ((value) ^= (1 << (bit)))

// マスクのマクロ
#define MASK_BITS(value, mask) ((value) & (mask))

int main() {
    uint16_t value = 0x06;  // 16進数の値

    // 左シフト
    uint16_t left_shifted = LEFT_SHIFT(value, 4);
    printf("左シフト: 0x%X\n", left_shifted);

    // 右シフト
    uint16_t right_shifted = RIGHT_SHIFT(value, 4);
    printf("右シフト: 0x%X\n", right_shifted);

    // ビットセット
    SET_BIT(value, 0);
    printf("ビットセット (0ビット目): 0x%X\n", value);

    // ビットクリア
    CLEAR_BIT(value, 0);
    printf("ビットクリア (0ビット目): 0x%X\n", value);

    // ビットトグル
    TOGGLE_BIT(value, 0);
    printf("ビットトグル (0ビット目): 0x%X\n", value);

    // マスク
    uint16_t masked = MASK_BITS(value, 0x0F0F);
    printf("ビットマスク: 0x%X\n", masked);

    return 0;
}