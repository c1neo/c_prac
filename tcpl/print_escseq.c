/*
 * K&R Exercise 1-10
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
		} else if (c == '\b') {
      			printf("\\b");
		} else if (c == '\\') {
			printf("\\\\");
		} else {
			putchar(c);
		}
	}
	return EXIT_SUCCESS;
}
