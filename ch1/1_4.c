#include<stdio.h>

/* Write a program to print the corresponding
   Celsius to Fahrenheit table. */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 150;
    step = 10;

    celsius = lower;
    printf("%s %s\n", "Celsius", "Farh");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * (celsius+32.0);
        printf("%-7.1f %-4.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}