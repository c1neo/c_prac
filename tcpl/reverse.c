/*
 * K&R Exercise 1-19
 * 17-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	1000

int knr_getline(char line[], int maxline);
void reverse(char s[], int max);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = knr_getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
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

void reverse(char s[], int max)
{
	char tmp;
	int left, right;

	for (right = 0; s[right] != '\n' && s[right] != '\0' && right < max; right++);

	right--;
	left = 0;

	while (left < right) {
		tmp = s[right];
		s[right] = s[left];
		s[left] = tmp;
		left++;
		right--;
	}

}
