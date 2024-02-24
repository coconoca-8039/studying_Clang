#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// 人物を表す構造体
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

int main() {

    Person Kotoha;

    memset(&Kotoha, 0, sizeof(Kotoha));
    
    // Kotoha = {'Kotoha', 25, 150};
    // Kotoha.name = 'Kotoha';
    strcpy(Kotoha.name, "Kotoha");
    Kotoha.age = 25;
    Kotoha.height = 155;

    // 結果を表示
    printf("Name: '%s'\n", Kotoha.name); 
    printf("Age: %d\n", Kotoha.age);
    printf("Height: %.2f\n", Kotoha.height);
    NEWLINE; 

    /*
    memset(&Kotoha, 0, sizeof(Kotoha));

    printf("Name: '%s'\n", Kotoha.name); 
    printf("Age: %d\n", Kotoha.age);
    printf("Height: %.2f\n", Kotoha.height);
    NEWLINE;
    */

    /*
    Name: 'Kotoha'
    Age: 25
    Height: 155.00
    Name: ''
    Age: 0
    Height: 0.00
    */
   
    Person Hanon;
    memcpy(&Hanon, &Kotoha, sizeof(Person));
    strcpy(Hanon.name, "Hanon"); 
    printf("Name: '%s'\n", Hanon.name); 
    printf("Age: %d\n", Hanon.age);
    printf("Height: %.2f\n", Hanon.height);
    NEWLINE;

    return 0;
}