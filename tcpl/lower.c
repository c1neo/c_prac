/*
 * K&R Exercise 2-10
 * 04-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		putchar(lower(c));
	}
	return EXIT_SUCCESS;
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}
