/*
 * K&R Exercise 2-2
 * 01-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	2048

int getline2(char *buf, int lim);

int main(void)
{
	char buffer[MAXLINE];

	while (getline2(buffer, MAXLINE) > 0) {
		printf("%s", buffer);
	}

	return EXIT_SUCCESS;
}

int getline2(char *buf, int lim)
{
	int c;
	int i = 0;
	/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) */
	while (i < lim - 1) {
		c = getchar();
		if (c == EOF) {
			return i;
		}
		buf[i++] = c;
		if (c == '\n') {
			buf[i] = '\0';
			return i;
		}
	}
	buf[i] = '\0';
	return i;
}
