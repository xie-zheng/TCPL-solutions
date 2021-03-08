#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include <ctype.h>     /* for getch() */

#define MAXOP 100      /* max size of operand or operator */
#define NUMBER '0'     /* signal that a number was found */

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
double peek(void);              /* ex4-4 */
void duplicate(void);         
void swaptop(void);
void clear(void);               /* ----- */
double modulo(double, double);  /* ex4-5 */
void ungets(char *);            /* ex4-7 */

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];    /* stack to store ops */

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero division\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push(modulo(pop(), op2));
            } else {
                printf("error: zero division\n");
            }
            break;
        case '\n':
            printf("result====>\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


double modulo(double op1, double op2)
{
    op2 = (op2 < 0) ? -op2 : op2;
    op1 = (op1 < 0) ? -op1 : op1;
    while (op1 > op2) {
        op1 -= op2;
    }
    return op1;
}



#define MAXVAL 100    /* maximum depth of val stack */

int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty");
        return 0.0;
    }
}

/* peek: print the top element without poping it */
double peek(void)
{
    if (sp > 0) {
        return val[sp];
    } else {
        printf("peek: stack empty");
        return 0.0;
    }
}

/* duplicate: duplicate the top element */
void duplicate(void)
{
    if (sp > 0) {
        push(peek());
    } else {
        printf("duplicate: stack empty");
    }
}

/* swap: swap the top 2 element */
void swap(void)
{
    if (sp > 1) {
        double op1 = pop();
        double op2 = pop();
        push(op1);
        push(op2);
    }
}

/* clear: clear the stack */
void clear(void)
{
    sp = 0;
}



/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    } 
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;    /* not a number */
    }
    i = 0;
    if (isdigit(c)) {  /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {   /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }   
    return NUMBER;
}



#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)   
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}



/* push back an entire string */
void ungets(char *s)
{
    while (*s) {
        ungetch(*s++);
    }    
}