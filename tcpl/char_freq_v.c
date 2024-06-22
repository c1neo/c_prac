/*
 * K&R Exercise 1-14
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>

#define	PRINT_ASCII_COUNT	95

int main(void)
{
	int c;
	int lengths[PRINT_ASCII_COUNT] = {0};

	while ((c = getchar()) != EOF) {
		if (c < 32) {
			continue;
		}

		lengths[c - 32]++;
	}

	for (int i = 0; i < PRINT_ASCII_COUNT; i++) {
		if (lengths[i] > 0) {
			printf("%c: ", i + 32);
			for (int j = 0; j < lengths[i]; j++) {
				putchar('#');
			}
			putchar('\n');
		}
	}

	return EXIT_SUCCESS;
}
