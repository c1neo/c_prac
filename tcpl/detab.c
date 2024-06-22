/*
 * K&R Exercise 1-20
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB_WIDTH	8

int main(void)
{
	int c;
	int col = 0, tab = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			tab = TAB_WIDTH - (col % TAB_WIDTH);

			for (int i = 0; i < tab; i++) {
				putchar(' ');
			}
			col += tab;
			continue;
		}

		putchar(c);
		col++;

		if (c =='\n') {
			col = 0;
		}
	}
	return EXIT_SUCCESS;
}
