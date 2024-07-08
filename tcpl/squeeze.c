/*
 * K&R Exercise 2-4
 * 07-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[] = "hello world!\n";
	char s2[] = "hw";

	printf("%s", s1);
	squeeze(s1, s2);
	printf("%s", s1);

	return EXIT_SUCCESS;
}

void squeeze(char s1[], char s2[])
{
	int squeezed;
	int i, j, x;

	for (i = j = 0; s1[i] != '\0'; i++) {
		squeezed = 0;
		for (x = 0; s2[x] != '\0'; x++) {
			if (s1[i] == s2[x]) {
				squeezed = 1;
			}
		}
		if (squeezed == 0) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}
