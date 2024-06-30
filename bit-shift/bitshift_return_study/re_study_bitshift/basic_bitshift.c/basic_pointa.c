#include <stdio.h>
#define NEWLINE printf("\n");

void keisan(int *x){  // ポインタとして宣言してやる
    *x = 25;  // xが指すその先に代入しないといけない
    // x = 25としても意味ない
}

void math(int n1, int n2, int *tashi, int *hiki){
    // 3と4の引数にはアドレスを与えている
    // そのためtashiとhikiは呼び出し側とアドレスを共有している
    *tashi = n1 + n2;
    *hiki = n1 - n2;
}

struct Fruits{
    char name[128];
    int price;
    int zaiko;
};

void modifyArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;  // 各要素を2倍にする
    }
}

int main() {
    // ポインタ
    // ポインタに数値は代入することはできない

    // 間接参照演算子 *
    // ポインタに*をつけるとそれが指す先のモノを表す

    // アドレス演算子 &
    // 変数のアドレスを取得するために使用

    // 関数を呼び出す方の引数には&をつける
    // 実行される関数側の引数に*をつける

    int apple = 10;
    int *p;
    p = &apple;
    printf("%d\n", apple);  // 10
    printf("%d\n", *p);     // 10
    printf("%p\n", p);      // 0x16f40ef8c
    NEWLINE;

    /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

    int mango = 10;
    printf("1回目 : %d\n", mango);
    keisan(&mango);  // mangoのアドレスを渡すようにする
    printf("Data Uploaded!\n");
    printf("2回目 : %d\n", mango);
    /*
    1回目 : 10
    2回目 : 25
    */
    NEWLINE;

    /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

    int num1 = 30;
    int num2 = 10;
    int tashizan = 0;
    int hikizan = 0;
    math(num1, num2, &tashizan, &hikizan);
    printf("足し算 : %d\n", tashizan);
    printf("引き算 : %d\n", hikizan);
    /*
    足し算 : 40
    引き算 : 20
    */
    NEWLINE;

    /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
    struct Fruits store = {"banana", 150, 50};
    struct Fruits *ptr;  // データ型は揃えておかないといけない
    ptr = &store;  // ポインタに対してアドレスを代入する
    printf("名前 : %s\n", (*ptr).name);  //store.nameと同じ
    printf("金額 : %d\n", (*ptr).price);  // 順番の問題で()大事
    printf("在庫 : %d\n", ptr->zaiko);  // アロー演算子でもいける
    NEWLINE;

    /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("元の配列: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    NEWLINE;

    modifyArray(numbers, size);  // 配列はポインタとして扱われるため&演算子は不要
    // modifyArray(&numbers[0], size);でも問題ない
    printf("変更後の配列: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

}