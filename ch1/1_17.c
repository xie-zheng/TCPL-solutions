#include <stdio.h>
#define MAXLINE 1000

int getlinegt(char line[], int maxline);

/* print all input lines that are longer than 80 */
main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = getlinegt(line, MAXLINE)) >= 0) {
        if (len == 0) {
            continue;
        }
        printf("len=%d %s", len, line);
    }
}

int getlinegt(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (i < 79) {
        return 0;
    }
    return i;
}