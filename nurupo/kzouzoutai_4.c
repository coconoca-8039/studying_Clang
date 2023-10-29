#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KAIGYO printf("\n");

// 構造体を比較する

// 動物を表す構造体
struct Animal{
    int age;
    char name[1];
};

struct Fish{
    int age;  // 4バイト
    char name[1];  // 1バイト
    // 4 + 1 = 5?
    // パディングが入るため8バイトになる
    // でもこれに頼るのはよくない
};

bool animal_equal(
    const struct Animal *lhs,  // レフトハンドサイド
    const struct Animal *rhs  // ライトハンドサイド
){
    return lhs->age == rhs->age && strcmp(lhs->name, rhs->name) == 0;
    // strcmpは2つの文字列が等しい時に0を返す
}

void dump(void *p, size_t size){
    void *end = p + size;

    for(int i = 0; p < end; i += 1, p+= 1){
        unsigned char byte = *(unsigned char *)p;
        printf("%dバイト目 : %d\n", i, byte);
    }
}

int main(void){

    struct Animal cat = {20, ""};
    struct Animal dog = cat;

    printf("cat age[%d] name[%s]\n", cat.age, cat.name);
    printf("dog age[%d] name[%s]\n", dog.age, dog.name);
    KAIGYO;

    dog.age = 33;

    if(animal_equal(&cat, &dog)){
        puts("2つの構造体は同じです\n");
    }else{
        puts("2つの構造体は別です\n");
    }

    // 構造体の比較でmemcmpの使用は非推奨

    printf("int size = %d\n", sizeof(int));
    printf("char size = %d\n", sizeof(char));
    printf("cat size = %d\n", sizeof(cat));
    KAIGYO;

    dump(&cat, sizeof(cat));

    return 0;
}