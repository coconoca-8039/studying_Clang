#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define PRINT_INT(var) printf("%d\n", var)
#define PRINT_CHAR(var) printf("%s\n", var)

// 構造体をコピーする

// 動物を表す構造体
struct Animal{
    int age;
    char name[40];
};

int main(void){
    printf("Hello World\n");
    
    struct Animal cat = {30, "Tama"};
    struct Animal dog = cat;
    struct Animal fish;
    struct Animal monkey;
    memcpy(&fish, &cat, sizeof(cat));  // 同じサイズだと正常に機能しない可能性がある
    memmove(&monkey, &cat, sizeof(cat));  // 同じサイズでも問題なし

    printf("cat age[%d] name[%s]\n", cat.age, cat.name);
    printf("dog age[%d] name[%s]\n", dog.age, dog.name);
    printf("fish age[%d] name[%s]\n", fish.age, fish.name);
    printf("monkey age[%d] name[%s]\n", monkey.age, monkey.name);

    return 0;
}