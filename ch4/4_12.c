#include <stdio.h>

char* itoa(int num, char* src, int count)
{
    char* str = (char*) malloc(sizeof(char) * (count + 2));
    strcpy(str, src);
    free(src);

    if (num) {
        *(str + count) = num / 10;
        return itoa(num, str, count + 1);
    }
    *(str + count) = '\0';
    return str;
}    