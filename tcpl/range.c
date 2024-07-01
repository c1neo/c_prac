/*
 * K&R Exercise 2-1
 * 01-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("CHAR_MIN: %d\n\n", CHAR_MIN);

	printf("UCHAR_MAX: %d\n\n", UCHAR_MAX);

	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("SHRT_MIN: %d\n\n", SHRT_MIN);

	printf("USHRT_MAX: %d\n\n", USHRT_MAX);

	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n\n", INT_MIN);

	printf("UINT_MAX: %u\n\n", UINT_MAX);

	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("LONG_MIN: %ld\n\n", LONG_MIN);

	printf("ULONG_MAX: %lu\n\n", ULONG_MAX);

	printf("LONG_LONG_MAX: %lld\n", LONG_LONG_MAX);
	printf("LONG_LONG_MIN: %lld\n\n", LONG_LONG_MIN);

	printf("ULONG_LONG_MAX: %llu\n\n", ULONG_LONG_MAX);

	printf("FLOAT_MAX: %e\n", FLT_MAX);
	printf("FLOAT_MIN: %e\n\n", FLT_MIN);

	printf("DOUBLE_MAX: %e\n", DBL_MAX);
	printf("DOUBLE_MIN: %e\n\n", DBL_MIN);

	return EXIT_SUCCESS;
}
