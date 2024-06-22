/*
 * K&R Exercise 1-13
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>

#define	MAX_LEN	16

int main(void)
{
	int c;
	int count = 0, max_count = 0, word_count = 0;
	int lengths[MAX_LEN] = {0};

	while ((c = getchar()) != EOF) {
		if (iswspace(c)) {
			// lengths array out of bound if word is too big
			if (count > 0) {
				lengths[count - 1]++;
				if (lengths[count - 1] > max_count) {
					max_count = lengths[count - 1];
				}
				count = 0;
				word_count++;
			}
		} else {
			count++;
		}
	}

	while (max_count > 0) {
		for (int i = 0; i < MAX_LEN; i++) {
			if (max_count <= lengths[i]) {
				printf(" # ");
			} else {
				printf("   ");
			}
		}
		putchar('\n');
		max_count--;
	}
	for (int i = 1; i <= MAX_LEN; i++) {
		printf("%2d ", i);
	}
	putchar('\n');

	printf("word count: %d\n", word_count);
	return EXIT_SUCCESS;
}
