/*
 * K&R Exercise 4-4
 * 03-08-2024
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void swap(void);
double top(void);

/* reverse polish calculator */
int main(void)
{
    int type;
    int last;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
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
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int) pop() % (int) op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '#':
            break;
        case '!':
            clear();
            break;
        case '~':
            swap();
            break;
        case '\n':
            if (last == '#') {
                printf("\t%.8g\n", top());
            } else {
                printf("\t%.8g\n", pop());
            }
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
        last = type;
    }

    return EXIT_SUCCESS;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* clear: set stack position to 0 (stack contents are ignored and eventuall overwritten) */
void clear(void)
{
    sp = 0;
}

/* top: return top element in the stack without moving stack position */
double top(void)
{
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* swap: swap top two elements */
void swap(void)
{
    if (sp > 1) {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    } else {
        printf("error: not enough elements in stack\n");
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    
    i = 0;
    if (c == '+' || c == '-') {
        c = getch();
        if (isdigit(c) || c == '.') {
            s[++i] = c;
        } else {
            ungetch(c);
            c = s[0];
        }
    }

    if(!isdigit(c) && c != '.') {
        return c;       /* not a number */
    }

    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {     /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buff */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}