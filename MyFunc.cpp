#include "MyFunc.h"
int mystrlen(char* src)
{
    int counter = 0;
    for(int c = 0; src[c] != '\0'; c++)
    {
        counter++;
    }
    return counter;
}
void mystrcpy(char* dst, char* src)
{
    for(int c = 0; c < mystrlen(src) + 1;c++)
        dst[c] = src[c];
}

