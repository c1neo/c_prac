/*
 * K&R Exercise 1-23
 * 22-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define NORM_MODE	0
#define	COM_MODE	1
#define SCOM_MODE	2
#define	CONS_MODE	3
#define STR_MODE	4

int main(void)
{
	int mode = NORM_MODE;
	int col = 0;
	int c = getchar();

	while (c != EOF) {
		if (c == '\'') {
			if (mode == NORM_MODE) {
				mode = CONS_MODE;
			} else if (mode == CONS_MODE) {
				mode = NORM_MODE;
			}
			if (mode != COM_MODE && mode != SCOM_MODE) {
				putchar(c);
			}
		} else if (c == '\"') {
			if (mode == NORM_MODE) {
				mode = STR_MODE;
			} else if (mode == STR_MODE) {
				mode = NORM_MODE;
			}
			if (mode != COM_MODE && mode != SCOM_MODE) {
				putchar(c);
			}
		} else if (c == '/' && mode == NORM_MODE) {
			if ((c = getchar()) == EOF) {
				putchar('/');
				break;
			}
			if (c == '*') {
				mode = COM_MODE;
			} else if (c == '/') {
				mode = SCOM_MODE;
			} else {
				putchar('/');
				putchar(c);
			}
		} else if (c == '*' && mode == COM_MODE) {
			if ((c = getchar()) == EOF) {
				break;
			}
			if (c == '/') {
				mode = NORM_MODE;
			}
		} else if (mode != COM_MODE && mode != SCOM_MODE) {
			putchar(c);
			if (c != '\n') {
				col++;
			}
		}

		if (c == '\n') {
			if (mode == COM_MODE && col > 1) {
				putchar(c);
			} else if (mode == SCOM_MODE) {
				mode = NORM_MODE;
				if (col > 1) {
					putchar(c);
				}
			}
			col = 0;
		}
		c = getchar();
	}

	return EXIT_SUCCESS;
}
