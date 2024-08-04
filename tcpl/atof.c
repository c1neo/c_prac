/*
 * K&R Exercise 4-2
 * 07-25-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100

/* rudimentary calculator */
int main(void)
{
    double sum, atof2(char []); /* didn't know that I can do this */
    char line[MAXLINE];
    int getline2(char line[], int max); /* or this */

    sum = 0;
    while (getline2(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }

    return EXIT_SUCCESS;
}

double atof2(char s[])
{
	double val, power, e_val, res;
	int i, sign, e_sign, e;
    
    for (i = 0; isspace(s[i]); i++);    /* skip white space */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (tolower(s[i]) == 'e') {
        i++;
    }

    e_sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        e_sign = s[i] == '+' ? 1 : -1;
        i++;
    }

    for (e = 0; isdigit(s[i]); i++) {
        e = 10 * e + (s[i] - '0');
    }

    res = sign * val / power;
    if (e == 0.0) {
        return res;
    }

    for (int i = 0, e_val = 1.0; i < e; i++) {
        e_val *= 10.0;
    }

    return e_sign == 1 ? res * e_val : res / e_val; 
}

/* getline2: get line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
