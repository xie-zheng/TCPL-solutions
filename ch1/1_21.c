#include <stdio.h>

void entab(int n);

main()
{
    entab(10);
}

void entab(int n)
{
    char c;
    int blanks;
    int counter = 0;

    while ((c = getchar()) != EOF) {
        blanks = 0;
        if (c == ' ') {
            blanks += 1;
            counter += 1;
            while ((c = getchar()) == ' ') {
                blanks += 1;
                counter += 1;
                /* replaces blanks by tab when reach tab stop */
                if (counter % n == 0) {
                    putchar('\t');
                    blanks = 0;
                }
            }
        }
        /* output the remaining blanks */
        for (int i = 0; i < blanks; i += 1)
            putchar(' ');
        
        /* handle normal inputs */
        if (c == '\n') {
            putchar('\n');
            counter = 0;
        } else {
            putchar(c);
            counter += 1;
        }
    }
}