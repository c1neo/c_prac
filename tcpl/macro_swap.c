/*
 * K&R Exercise 4-14
 * 03-08-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define swap(t, x, y)   { \
    t tmp = x; \
    x = y; \
    y = tmp; \
}

int main(void)
{
    int x = 0, y = 1;
    printf("x: %d\ty: %d\n", x, y);
    swap(int, x, y);    /* semicolon not actually required */
    printf("x: %d\ty: %d\n", x, y);

    return EXIT_SUCCESS;
}