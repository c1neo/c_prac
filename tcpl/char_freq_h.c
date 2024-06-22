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
	int max_count = 0;
	int lengths[PRINT_ASCII_COUNT] = {0};

	while ((c = getchar()) != EOF) {
		if (c < 32) {
			continue;
		}

		lengths[c - 32]++;

		if (lengths[c - 32] > max_count) {
			max_count = lengths[c - 32];
		}
	}

	while (max_count > 0) {
		for (int i = 0; i < PRINT_ASCII_COUNT; i++) {
			if (lengths[i] == 0) {
				continue;
			}
			if (max_count <= lengths[i]) {
				printf("# ");
			} else {
				printf("  ");
			}
		}
		putchar('\n');
		max_count--;
	}

	for (int i = 0; i < PRINT_ASCII_COUNT; i++) {
		if (lengths[i] == 0) {
			continue;
		}
		printf("%c ", i + 32);
	}
	putchar('\n');

	return EXIT_SUCCESS;
}
