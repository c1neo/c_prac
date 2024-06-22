/*
 * K&R Exercise 1-21
 * 18-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB_LENGTH	8

int main(void)
{
	int c;
	int count = 0, col = 0;
	int spaces = 0, tabs = 0;
	
	while ((c = getchar()) != EOF) {

		if (c == ' ') {
			count++;
		} else {
			if (count > 0) {
				/* tabs here is amount of spaces to fill tab */
				tabs = TAB_LENGTH - (col % TAB_LENGTH);
				if (tabs <= count) {
					putchar('\t');
					count -= tabs;
					col += tabs;
				}

				/* tabs here is amount of tabs to replace spaces */
				tabs = count / TAB_LENGTH;
				count -= (TAB_LENGTH * tabs);
				col += (TAB_LENGTH * tabs);
				for (int i = 0; i < tabs; i++) {
					putchar('\t');
				}

				spaces = count % TAB_LENGTH;
				for (int i = 0; i < spaces; i++) {
					putchar(' ');
					count--;
				}
				col += spaces;
			}

			col++;
			if (c == '\n') {
				col = 0;
			}
			putchar(c);
		}
	}
	return EXIT_SUCCESS;
}
