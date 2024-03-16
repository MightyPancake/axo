#ifndef UTIL_MEM_H
#include <string.h>
#define UTIL_MEM_H
    char* strapnd(char** str, const char* addition){
    *str = (char*)realloc(*str, strlen(*str) + strlen(addition) + 1);
    if (NULL == *str)
        printf("STRAPND ERROR!\n");
    *str = strcat(*str, addition);
    return *str;
}
#endif