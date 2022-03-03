#include <stdio.h>

int callprint(char* brand, char* name, char* type, char* engine, char* max_price, char* color){
    printf("%s %s %s %s %s %s\n", brand, name, type,engine, max_price, color);
    return 1;
} 