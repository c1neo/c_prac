/*
 * K&R Exercise 2-5
 * 04-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LPS_SIZE	1024
#define LPS_END		-1

int any_brute(char *s1, char *s2);
int any_kmp(char *s1, char *s2);

int main(void)
{
	return EXIT_SUCCESS;
}

int any_brute(char *s1, char *s2)
{
	int s1_len;
	int s2_len;

	int pos = 0;

	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++);
	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++);

	for (pos = 0; pos < s1_len; pos++) {
		int i = pos, j = 0;
		while (i < s1_len && j < s2_len && s1[i] == s2[j]) {
			i++;
			j++;
		}
		if (s2[j] == '\0') {
			break;
		}
	}

	if (s1[pos] == '\0') {
		pos = -1;
	}

	return pos;
}

int any_kmp(char *s1, char *s2)
{
	/* limited version of kmp algorithm */
	int s1_len;
	int s2_len;
	int lps[LPS_SIZE] = {0}; /* longest proper suffix */

	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++);
	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++);
	if (s2_len > (LPS_SIZE - 1)) {
		return -1;
	} else if (s2_len == 0) {
		return 0;
	}

	lps[s2_len] = LPS_END;

	int curr = 1;
	int prev = 0;
	while (curr < s2_len) {
		if (s2[curr] == s2[prev]) {
			lps[curr] = prev + 1;
			curr++;
			prev++;
		} else if (prev == 0) {
			lps[curr] = 0;
			curr++;
		} else {
			prev = lps[prev - 1];
		}
	}

	int s1_idx = 0;
	int s2_idx = 0;
	while (s1_idx < s1_len) {
		if (s1[s1_idx] == s2[s2_idx]) {
			s1_idx++;
			s2_idx++;
		} else if (s2_idx == 0) {
			s1_idx++;
		} else {
			s2_idx = lps[s2_idx - 1];
		}

		if (lps[s2_idx] == LPS_END) {
			return s1_idx - s2_len;
		}
	}

	return -1;
}
