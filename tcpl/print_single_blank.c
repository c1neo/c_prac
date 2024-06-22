/*
 * K&R Exercise 1-9
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	IN	1
#define OUT	0

int main(void)
{
	int c;
	int ws = OUT;

	while ((c = getchar()) != EOF) {
    		if (c == ' ') {
			if (ws == OUT) {
        			putchar(c);
        			ws = IN;
      			}
    		} else {
      			ws = OUT;
      			putchar(c);
    		}
  	}

  	return EXIT_SUCCESS;
}
