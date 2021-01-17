#include <stdio.h>

#define IN  0    /* inside a word */
#define OUT 1    /* outside a word */

/* print input one word per line */
main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                printf("\n");
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }
}
