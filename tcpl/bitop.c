/*
 * K&R Exercise 2-6, 2-7, 2-8, 2-9
 * 08-07-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define	INT_BITS	(sizeof(int) * CHAR_BIT)

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);
unsigned int rightrot(unsigned int x, int n);
unsigned int bitcount1(unsigned int x);
unsigned int bitcount2(unsigned int x);
void print_bits(unsigned int x);

int main(void)
{
	return EXIT_SUCCESS;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	int shift_size = p + 1 - n;
	unsigned int mask = ~(~0 << n);
	unsigned int y_bit = (y & mask) << shift_size;
	mask <<= shift_size;
	return (x & ~mask) | y_bit;
}

unsigned int invert(unsigned int x, int p, int n)
{
	int shift_size = p + 1 - n;
	unsigned int i_bit = (~(x >> shift_size) & ~(~0 << n)) << shift_size;
	unsigned int mask = ~(~(~0 << n) << shift_size);
	return (x & mask) | i_bit;
}

unsigned int rightrot(unsigned int x, int n)
{
	unsigned int mask = ~((~0) << n);
	mask = (mask & x) << (INT_BITS - n);
	return (x >> n) | mask;
}

unsigned int bitcount1(unsigned int x)
{
	int b;
	for (b = 0; x != 0; x >>= 1) {
	 	if (x & 01)
			b++;
	}
	return b;
}

unsigned int bitcount2(unsigned int x)
{
	int b;
	for (b = 0; x > 0; x &= (x - 1), b++);
	/*
	 * If x is odd number, the first bit is always 1 so x &= (x - 1)
	 * deletes the rightmost bit.
	 * If x is even number, x - 1 turns every bit on the right side of current rightmost bit to 1 while
	 * turning on the current rightmost bit itself to 0. x have every bit on the right side of the
	 * current rightmost bit as 0 so x &= (x - 1) again turns off the rightmost bit.
	 */
	return b;
}

void print_bits(unsigned int x)
{
	for (int i = INT_BITS - 1; i >= 0; i--) {
		printf("%d", (x >> i) & 1);
	}
	printf("\n");
}
