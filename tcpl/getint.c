/**
 * K&R Exercise 4-1
 * 10-03-2025
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getch(void);
void ungetch(int);
int getint(int*);

int main(void)
{
	int c, pn;
	c = getint(&pn);
	printf("pn: %d, c = %c\n", pn, c);
	return EXIT_SUCCESS;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	*pn = 0;
	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			if (c != EOF)
				ungetch(c);
			c = (sign == 1) ? '+' : '-';
			ungetch(c);
			return c;
		}
	}
	for (; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define	BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
