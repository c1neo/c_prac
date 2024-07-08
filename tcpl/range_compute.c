/*
 * K&R Exercise 2-1
 * 08-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	/*
	 * integer overflow is undefined behaviour
	 */
	int x, y;
	x = y = 0;
	while (y >= 0) {
		x = y + 1;
		y = x * 2;
	}
	printf("INT_MAX: %d\n", x);
	printf("INT_MIN by overflow: %d\n", x + 1);

	x = y = 0;
	while (y <= 0) {
		x = y - 1;
		y = x * 2;
	}
	x -= 1;
	printf("INT_MIN: %d\n", x);
	printf("INT_MAX by overflow: %d\n", x - 1);

	unsigned int ux = ~0;
	printf("UINT_MAX: %u\n", ux);

	/*
	 * computing maximum and minimum value (range) of float requires more study
	 */

	return EXIT_SUCCESS;
}
