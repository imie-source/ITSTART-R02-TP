#include <stdlib.h>
#include <string.h>
#include "../include/strndup.h"
 
char* strndup(const char*  s, int n) {
    int slen = (int)strlen(s);
    char* copy;
 
    if (slen < n) {
        n = slen;
    }
 
    copy = malloc(n+1);
 
    if (copy){
        memcpy(copy, s, n);
        copy[n] = 0;
    }
 
    return copy;
}