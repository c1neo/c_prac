/*
 * K&R Exercise 3-3
 * 17-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main(void)
{
	char s1[] = "-a-zA-Z0-9-";
	char s2[1000];

	expand(s1, s2);

	printf("%s\n", s2);

	return EXIT_SUCCESS;
}

void expand(char s1[], char s2[])
{
	int i, j;
	char from = 0, to = 0;

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		from = s1[i];
		if (s1[i + 1] == '-' && s1[i + 2] != '\0') {
			to = s1[i + 2];
			i += 2;
		} else {
			to = s1[i];
		}

		/*
		 * error checking required for things like from being bigger than to
		 */

		for (; from <= to; from++) {
			s2[j++] = from;
		}
	}
	s2[j] = '\0';
}
