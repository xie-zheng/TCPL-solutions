#include <stdio.h>
#define MAXLINE 1000

int getlinerip(char line[], int maxline);

/* remove trailing blanks and tabs 
 *  delete entirely blank lines */
main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = getlinerip(line, MAXLINE)) >= 0) {
        if (len == 0) {
            continue;
        }
        printf("len:%d %s", len, line);
    } 
}


int getlinerip(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        for (; (s[i-1] == '\t' || s[i-1] == ' ') && i > 0; --i)
            ;
        if (i == 0) {
            s[i] = '\0';
            return 0;
        }
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}