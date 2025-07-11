#ifndef BYTEFORGE_H
#define BYTEFORGE_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static inline bool isOption(char *str){
    return str[0] == '-';
}
static inline bool isFile(char *str){
    if(isOption(str)) return false;
    return true;
}
static inline bool isNumber(char *str){
    for(int i = 0; i < strlen(str); i++){
        char x = str[i];
        switch (x)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            continue;
        default:
            return false;
        }
    }
    return true;
}
static inline int getIntChar(char x){
    switch (x)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
}
static inline long long int getIntNumber(char *str){
    long long int res = 0;
    for(int i = 0; i < strlen(str); i++){
        res *= 10;
        res += getIntChar(str[i]);
    }
    return res;
}

#endif