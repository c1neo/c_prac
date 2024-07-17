/*
 * K&R Exercise 3-4, 3-5, 3-6
 * 17-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);
void itoa2(int n, char s[]);
void itoa3(int n, char s[], int width);
void itob(int n, char s[], int b);

int main(void)
{
	char buffer[128];

	itob(160, buffer, 8);
	printf("%s\n", buffer);

	return EXIT_SUCCESS;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}

void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) {	/* record a sign */
		n = -n;		/* make n positive */
	}

	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);
}

void itoa2(int n, char s[])
{
	/*
	 * K&R Exercise 3-4
	 * original itoa cannot handle the largest negative number because
	 * the transformation to string happens after n becoming positive number
	 * in which the biggest positive number have smaller absolute value compared to
	 * negative number by 1.
	 */
	int i, sign;
	if (n > 0) {
		sign = 1;
	} else {
		sign = -1;
	}

	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = sign * (n % (10 * sign)) + '0';	/* get next digit */
	} while ((n /= 10) != 0);				/* delete it */

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void itoa3(int n, char s[], int width)
{
	/*
	 * K&R Exercise 3-6
	 */
	int i, sign, curr_w;
	if (n > 0) {
		sign = 1;
	} else {
		sign = -1;
	}

	i = 0;
	curr_w = 0;
	do {	/* generate digits in reverse order */
		s[i++] = sign * (n % (10 * sign)) + '0';	/* get next digit */
		curr_w++;
	} while ((n /= 10) != 0);				/* delete it */

	if (sign < 0) {
		s[i++] = '-';
		curr_w++;
	}

	/* pad the output with given minimum width */
	for (; curr_w < width; curr_w++) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void itob(int n, char s[], int b)
{
	/*
	 * K&R Exercise 3-5
	 */
	int i, sign, curr;
	if (n > 0) {
		sign = 1;
	} else {
		sign = -1;
	}

	i = 0;
	do {
		curr = sign * (n % (b * sign));
		curr = curr > 9 ? curr - 10 + 'A' : curr + '0';
		s[i++] = curr;
	} while ((n /= b) != 0);

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
