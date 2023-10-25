#include <stdio.h>
#include <stdint.h>

enum Days{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

enum Colors{Red=1, Grean=4, Blue=8};

typedef enum {
    SUN, MON, TUE, WED, THU, FRI, SAT
} Weekday;


int main(){

    Weekday today = MON;

    switch(today) {
        case SUN:
            printf("Today is Sunday.\n");
            break;
        case MON:
            printf("Today is Monday.\n");
            break;
        // ... 他の曜日も同様
    }
}