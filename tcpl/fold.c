/*
 * K&R Exercise 1-22
 * 18-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	80

int fold_getline(char s[], int curr, int max);
int clean_buffer(char s[], int curr, int max);

int main(void)
{
	int curr = 0;
	char buffer[MAXLINE];
	while ((curr = fold_getline(buffer, curr, MAXLINE)) > 0) {
		if (buffer[curr - 1] == '\n') {
			printf("%s", buffer);
			curr = 0;
		} else {
			printf("%s\n", buffer);
			curr = clean_buffer(buffer, curr + 1, MAXLINE);
		}
	}
	
	return EXIT_SUCCESS;
}

int fold_getline(char s[], int curr, int max) 
{
	int c;
	int last_space = 0;

	for (; curr < max - 1 && (c = getchar()) != EOF && c != '\n'; curr++) {
		s[curr] = c;
		if (c == ' ' || c == '\t') {
			last_space = curr;
		}
	}

	if (c == '\n') {
		s[curr++] = '\n';
	} else if (last_space > 0) {
		curr = last_space;
	} 
	s[curr] = '\0';

	return curr;
}

int clean_buffer(char s[], int curr, int max)
{
	int i;
	for (i = 0; curr < max - 1; curr++, i++) {
		s[i] = s[curr];
	}
	return i;
}
