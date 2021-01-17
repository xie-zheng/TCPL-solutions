#include <stdio.h>

void detab();

main()
{
    detab(10);
}

/* write a program detab that replaces tabs in the input
    with the proper number of blanks to the next tab stop */
void detab(int n)
{
    char c;
    int blanks;
    int counter = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            blanks = n - (counter % n);
            for (int i = 0; i < blanks; i += 1) {
                putchar(' ');
                counter += 1;
            }
        } else if (c == '\n') {
            putchar('\n');
            counter = 0;
        } else {
            putchar(c);
            counter += 1;
        }
    }
}