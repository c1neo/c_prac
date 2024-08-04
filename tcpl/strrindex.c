/*
 * K&R Exercise 4-1
 * 24-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	1000	/* maximum input line length */

int getline2(char line[], int max);
int strrindex(char source[], char searchfor[]);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	int index;

	while (getline2(line, MAXLINE) > 0) {
		if ((index = strrindex(line, argv[1])) >= 0) {
			printf("index: %d - %s", index, line);
			found++;
		}
	}
	return found;
}

/* getline2: get line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

/* strrindex: return index of rightmost t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k;
	int index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0') {
			index = i;
		}
	}
	return index;
}
