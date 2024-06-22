/*
 * K&R Exercise 1-24
 * 22-06-2024
 */

/*
 * This program currently doesn't check angled brackets for #include <header>
 */

#include <stdio.h>
#include <stdlib.h>

#define	VALID		1
#define INVALID		0

#define NOTBRKT		0
#define OPENBRKT	1
#define CLSBRKT		(-1)
#define BRKTBUFFSIZE	1024

int check_char(void);
int check_str(void);
int check_com(int *row);
int check_octal(void);
int check_hexa(void);
char counterpart_bracket(char c);
int isbracket(char c);

int main(void)
{
	char brkt_buffer[BRKTBUFFSIZE] = { 0 };
	int brkt_idx = 0;

	int c;
	int brkt;
	int status = VALID;
	int row = 0;
	char cbrkt;

	while ((c = getchar()) != EOF) {
		brkt = isbracket(c);
		if (brkt == OPENBRKT) {
			if (brkt_idx == BRKTBUFFSIZE) {
				/* this is not really an error but you really shouldn't... */
				status = INVALID;
				printf("ERROR: TOO MANY BRACKET NESTS: row %d\n", row + 1);
				break;
			}
			brkt_buffer[brkt_idx++] = c;
			continue;
		} else if (brkt == CLSBRKT) {
			cbrkt = counterpart_bracket(brkt_buffer[--brkt_idx]);
			if (cbrkt != c) {
				status = INVALID;
				printf("ERROR: UNMATCHING BRACKETS: %c-%c : row: %d\n", cbrkt, c, row + 1);
				break;
			}
			continue;
		}

		if (c == '\'') {
			status = check_char();
		} else if (c == '\"') {
			status = check_str();
		} else if (c == '/') {
			c = getchar();
			if (c == EOF) {
				printf("ERROR: DIVISION OPERATOR REQUIRES 2 OPERANDS\n");
				break;
			} else if (c == '*') {
				status = check_com(&row);
			}
			/* single line comments need no checking */
		}

		if (status == INVALID) {
			break;
		}
		if (c == '\n') {
			row++;
		}
	}

	if (brkt_idx != 0 && status == VALID) {
		printf("ERROR: UNCLOSED BRACKET EXIST: %d\n", brkt_idx);
	} else if (status == VALID) {
		printf("THIS CODE IS SYNTACTICALLY RELATIVELY CORRECT\n");
	}

	return EXIT_SUCCESS;
}

int isbracket(char c)
{
	if (c =='(' || c =='[' || c == '{') { // || c == '<') {
		return OPENBRKT;
	} else if(c == ')' || c == ']' || c == '}') { //|| c == '>') {
		return CLSBRKT;
	}
	return NOTBRKT;
}

int check_hexa(void)
{
	int c;
	for (int i = 0; i < 2; i++) {
		c = getchar();
		if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
			return INVALID;
		}
	}
	return VALID;
}

int check_octal(void)
{
	int c;
	for (int i = 0; i < 2; i++) {
		c = getchar();
		if (!(c >= '0' && c <= '8')) {
			return INVALID;
		}
	}
	return VALID;
}

int check_str(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			printf("ERROR: INVALID STRING CONSTANT\n");
			return INVALID;
		}
		if (c == '\"') {
			break;
		}
	}
	if (c == EOF) {
		printf("ERROR: INVALID STRING CONSTANT\n");
		return INVALID;
	}
	return VALID;
}

int check_com(int *row)
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '*') {
			c = getchar();
			if (c == '/') {
				break;
			}
		} else if (c == '\n') {
			*row += 1;
		}
	}

	if (c == EOF) {
		return INVALID;
	}

	return VALID;
}

int check_char(void)
{
	int c = getchar();
	if (c == '\\') {
		/* check escape sequence */
		c = getchar();
		switch(c) {
		case 'a': case 'b': case 'f': case 'n': case 'r': case 't':
		case 'v': case '\\': case '?': case '\'': case '\"':
	 		break;
		case 'o':
			if (check_octal() == INVALID) {
				printf("ERROR: INVALID OCTAL CONSTANT\n");
				return INVALID;
			}
			break;
		case 'x':
			if (check_hexa() == INVALID) {
				printf("ERROR: INVALID HEXADECIMAL CONSTANT\n");
				return INVALID;
			}
			break;
		default:
			printf("ERROR: INVALID CHARACTER CONSTANT: INVALID ESCAPE SEQUENCE\n");
			return INVALID;
		}
	}
	if ((c = getchar()) != '\'') {
		printf("ERROR: INVALID CHARACTER CONSTANT\n");
		return INVALID;
	}
	return VALID;
}

char counterpart_bracket(char c)
{
	if (c == '(') {
		return ')';
	} else if (c ==')') {
		return '(';
	} else if (c == '[') {
		return ']';
	} else if (c ==']') {
		return '[';
	} else if (c == '{') {
		return '}';
	} else if (c == '}') {
		return '{';
	// } else if (c == '<') {
		// return '>';
	// } else if (c == '>') {
		// return '<';
	}
	return c;
}
