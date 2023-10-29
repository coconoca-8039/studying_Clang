#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sqlite3.h>

#define PRINT_INT(var) printf(#var " = %d\n", var)
#define PRINT_CHAR(var) printf(#var " = %s\n", var)

int main(){
    int i = 100;
    PRINT_INT(i);

    char c[] = "kotoha";
    PRINT_CHAR(c);
} 





