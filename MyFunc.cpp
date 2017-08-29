#include "Functions.h"
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
bool mystrcmp(char* src1, char* src2)
{
    if(mystrlen(src1) != mystrlen(src2))
        return false;
    for(int c = 0; c < mystrlen(src1); c++)
    {
        if(src1[c] != src2[c])
            return false;
    }
    return true;
}
