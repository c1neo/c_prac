/*
 * K&R Exercise 1-16
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	1000

int knr_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	int len, max, extend;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0) {
		extend = 0;
		while (line[len - 1] != '\n') {
			extend += len;
			len = knr_getline(line, MAXLINE);
		}
		len += extend;

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("%d\n%s", max, longest);
	}

	return EXIT_SUCCESS;
}

int knr_getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}
	
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	for (int i = 0; (to[i] = from[i]) != '\0'; i++);
}
