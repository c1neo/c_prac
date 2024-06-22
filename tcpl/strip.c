/*
 * K&R Exercise 1-18
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	1000

int knr_getline(char line[], int maxline);
int strip(char s[], int len);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = knr_getline(line, MAXLINE)) > 0) {
		if ((len = strip(line, len)) > 0) {
			printf("%s", line);
		}
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

int strip(char s[], int len)
{
	/* assume that line always properly ends with newline */
	int i;
	int start = 0, end = len - 2;

	while (s[start] == '\t' || s[start] == ' ') {
		start++;
	}

	while (end >= 0 && (s[end] == '\t' || s[end] == ' ')) {
		end--;
	}
	i = end + 1;

	if ((end - start + 1) <= 0) {
		return 0;
	}

	if (start > 0) {
		for (i = 0; start <= end; start++, i++) {
			s[i] = s[start];
		}
	}
	s[i++] = '\n';
	s[i] = '\0';

	return i;
}
