#include <stdio.h>

#define LONGEST 45
#define IN 1
#define OUT 0
#define YES 1
#define NO 0

/* print a histogram of the lengths of words in its input. */

void histogram_hori(int*);  /* print histogram horizontal */
void histogram_verti(int*); /* print histogram vertical */

main()
{
    int histogram[LONGEST];
    int c, i, state, length;

    for (i = 0; i < LONGEST; ++i) {
        histogram[i] = 0;
    }

    state = OUT;
    length = 0;
    /* read the input */
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            if (state == OUT) {
                state = IN;
            }
            ++length;
        } else {
            if (state == IN) {
                state = OUT;
                ++histogram[length-1];
                length = 0;
            }
        }
    }

    printf("\nhorizontal\n\n");
    histogram_hori(histogram);

    printf("\nvertival\n\n");
    histogram_verti(histogram);
}

void histogram_hori(int* histogram)
{
    int i, j;

    for (i = 0; i < LONGEST; ++i) {
        /* skip when no count */
        if (histogram[i] == 0) {
            continue;
        }

        printf("%-3d", i + 1);
        for (j = 0; j < histogram[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void histogram_verti(int* histogram)
{
    int i, j, max;
    int has_value[LONGEST];
    int copy[LONGEST];

    max = 0;
    for (i = 0; i < LONGEST; ++i) {
        /* copy so nondestructive */
        copy[i] = histogram[i];
        /* find max */
        if (histogram[i] > max)
            max = histogram[i];
        /* skip no value */
        has_value[i] = OUT;
        if (histogram[i] > 0) {
            has_value[i] = IN;
            printf("%3d", i + 1);
        }
    }
    printf("\n");

    for (j = 0; j < max; ++j) {
        printf(" ");
        for (i = 0; i < LONGEST; i++) {
            if (has_value[i] == OUT)
                continue;
            if (copy[i] > 0) {
                printf(" * ");
                --copy[i];
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}