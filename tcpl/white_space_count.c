/*
 * K&R Exercise 1-8
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	int blank, tab, newline;

  	blank = tab = newline = 0;
	
	while ((c = getchar()) != EOF) {
    		if (c == ' ') {
			blank++;
		} else if (c == '\t') {
			tab++;
		} else if (c == '\n') {
      			newline++;
    		}
	}

	printf("blanks: %d\ntabs: %d\nnewlines: %d\n", blank, tab, newline);

	return EXIT_SUCCESS;
}
