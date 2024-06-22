/*
 * K&R Exercise 1-13
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	MAX_LEN	16

int main(void)
{
	int c;
	int count = 0, max_count = 0;
	int lengths[MAX_LEN] = {0};

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (count > 0) {
				lengths[count - 1]++;
				if (lengths[count - 1] > max_count) {
					max_count = lengths[count - 1];
				}
				count = 0;
			}
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			count++;
		}
	}

	for (int i = 0; i < MAX_LEN; i++) {
		printf("%2d: ", i + 1);

		for (int j = 0; j < lengths[i]; j++) {
			putchar('#');
		}
		putchar('\n');
	}

	return EXIT_SUCCESS;
}
