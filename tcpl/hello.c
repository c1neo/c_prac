#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (puts("Hello, world!") == EOF) {
		exit(EXIT_FAILURE);
	} else {
		exit(EXIT_SUCCESS);
	}
}
