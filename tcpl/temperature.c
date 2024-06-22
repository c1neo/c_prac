/*
 * K&R Exercise 1-15
 * 16-06-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

float cels_fahr(int cels);
float fahr_cels(int fahr);

int main(void) {
	for (int fahr = 0; fahr < UPPER; fahr += STEP) {
		printf("%3d %6.1f\n", fahr, fahr_cels(fahr));
  	}
	return EXIT_SUCCESS;
}

float cels_fahr(int cels) {
	return (9.0 / 5.0) * cels + 32;
}

float fahr_cels(int fahr) {
	return (5.0 / 9.0) * (fahr - 32);
}
