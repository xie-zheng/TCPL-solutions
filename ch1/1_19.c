#include <stdio.h>
#define MAXLINE 1000

void reverse(char line[], int len);
int mygetline(char line[], int maxline);

/* reverse input a line at a time */
main()
{
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("len=%d %s", len, line);
    }
}

void reverse(char s[], int len)
{
    int i;
    int temp;
    len = len - 1;
    for (i = 0; i < len/2; ++i) {
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

int mygetline(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}