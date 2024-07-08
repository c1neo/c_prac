/*
 * K&R Exercise 2-3
 * 08-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int htoi(char s[]);

int main(void)
{
	printf("%d\n", htoi("0X24F1A"));
	return EXIT_SUCCESS;
}

int htoi(char s[])
{
	int i = 0, res = 0, curr = 0;

	if (s[0] == '\0') {
		return res;
	} else if (s[0] == '0' && tolower(s[1]) == 'x') {
		i = 2;
	}

	for (; s[i] != '\0'; i++) {
		curr = tolower(s[i]);
		if (curr >= '0' && curr <= '9') {
			curr -= '0';
		} else if (curr >= 'a' && curr <= 'f') {
			curr -= 'a' - 10;
		}
		res = res * 16 + curr;
	}

	return res;
}
