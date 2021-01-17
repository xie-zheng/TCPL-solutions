#include <stdio.h>

float tocelsis(float);

/* converse temprature using function */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = tocelsis(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float tocelsis(float fahr)
{
    float celsius;
    celsius = (fahr-32) * 5 / 9;
    return celsius;
}