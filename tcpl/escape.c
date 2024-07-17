/*
 * K&R Exercise 3-2
 * 17-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define	BUFFER_SIZE	1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int knr_getline(char s[], int lim);

int main(void)
{
	char line[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	while (knr_getline(line, BUFFER_SIZE) > 0) {
		escape(line, buf1);
		printf("escaped: %s\n", buf1);
		unescape(buf1, buf2);
		printf("unescaped: %s\n", buf2);
	}

	return EXIT_SUCCESS;
}

void escape(char s[], char t[])
{
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\a':
			t[j++] = '\\';
			t[j++] = 'a';
			break;
		case '\b':
			t[j++] = '\\';
			t[j++] = 'b';
			break;
		case '\f':
			t[j++] = '\\';
			t[j++] = 'f';
			break;
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\r':
			t[j++] = '\\';
			t[j++] = 'r';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		case '\v':
			t[j++] = '\\';
			t[j++] = 'v';
			break;
		case '\\':
			t[j++] = '\\';
			t[j++] = '\"';
			break;
		case '\?':
			t[j++] = '\\';
			t[j++] = '?';
			break;
		case '\'':
			t[j++] = '\\';
			t[j++] = '\'';
			break;
		case '\"':
			t[j++] = '\\';
			t[j++] = '\"';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] == '\\') {
			switch (s[++i]) {
			case 'a':
				t[j++] = '\a';
				break;
			case 'b':
				t[j++] = '\b';
				break;
			case 'f':
				t[j++] = '\f';
				break;
			case 'n':
				t[j++] = '\n';
				break;
			case 'r':
				t[j++] = '\r';
				break;
			case 't':
				t[j++] = '\t';
				break;
			case 'v':
				t[j++] = '\v';
				break;
			case '\\':
				t[j++] = '\\';
				break;
			case '?':
				t[j++] = '\?';
				break;
			case '\'':
				t[j++] = '\'';
				break;
			case '\"':
				t[j++] = '\"';
				break;
			default:
				t[j++] = s[i];
				break;
			}
		} else {
			t[j++] = s[i];
		}
	}
	t[j] = '\0';
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
