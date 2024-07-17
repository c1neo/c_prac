/*
 * K&R Exercise 3-1
 * 16-07-2024
 */

#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void)
{
	return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high) {
		/* mid = (low + high) / 2 */
		mid = low + ((high - low) / 2);
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			/* found match */
			return mid;
		}
	}
	return -1;	/* no match */
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low < high) {
		/* mid = (low + high) / 2 */
		mid = low + ((high - low) / 2);
		if (x <= v[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return x == v[high] ? high : -1;
}
