/*
 * K&R Exercise 1-17
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MINLINE	80

int main(void)
{
	int curr = 0;
	char buffer[MINLINE + 1] = {0};

	int c;
	while ((c = getchar()) != EOF) {
		if (curr < MINLINE) {
			buffer[curr] = c;
		} else if (curr == MINLINE) {
			printf("%s", buffer);
			putchar(c);
		} else {
			putchar(c);
		}
		curr++;

		if (c == '\n') {
			curr = 0;
		}
	}

	return EXIT_SUCCESS;
}
