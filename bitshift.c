#include <stdio.h>
#include <stdint.h>

// 符号付き整数で右シフトを行う場合、最上位ビット（符号ビット）がコピーされることがある
// この挙動はプラットフォームに依存するため、unsigned intの使用を推奨

int hexToBinary(uint32_t hex)
{
    for (int i = 31; i >= 0; i--)
    {
        if ((hex & (1 << i)))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

        if (i % 4 == 0)
        { // 4ビットごとにスペースを挿入
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

unsigned int rightShift(unsigned int value, int shiftAmount)
{
    return value >> shiftAmount;
}

unsigned int leftShift(unsigned int value, int shiftAmount)
{
    return value << shiftAmount;
}

int main()
{
    // 右シフト
    unsigned int before_bin = 0xAF;    // 元の16進数
    unsigned int right_shift_bin;      // 変換後の16進数
    unsigned int exchange_before_bin;  // 元の形の2進数
    unsigned int exchange_right_shift; // 変換後の 2進数

    printf("シフト前16進数:%X\n", before_bin);
    exchange_before_bin = hexToBinary(before_bin);
    right_shift_bin = rightShift(before_bin, 3);
    printf("シフト後16進数:%X\n", right_shift_bin);
    exchange_right_shift = hexToBinary(right_shift_bin);
    printf("\n");

    // 左シフトx配列
    int i;
    uint8_t myarray[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    printf("左シフト前の配列\n");
    for (i = 0; i < 8; i++)
    {
        printf("%02X ", myarray[i]);
    }
    printf("\n");

    printf("左シフト後の配列\n");
    int j = 0;
    for (j = 0; j < 8; j++)
    {
        myarray[j] = leftShift(myarray[j], 3);
        printf("%02X ", myarray[j]);
    }
    printf("\n");

    return 0;
}