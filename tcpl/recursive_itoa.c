/* 
 * K&R Exercise 4-12
 * 04-08-2024
 */

#include <stdio.h>
#include <stdlib.h>

#define ASIZE   1000

void itoa(int src, char dest[], int max);

int main(void)
{
    char line[ASIZE];
    itoa(0, line, ASIZE);
    printf("%s\n", line);
    return EXIT_SUCCESS;
}

int itoa_step(int src, char dest[], int start)
{
    int len;
    if (src / 10) {
        len = itoa_step(src / 10, dest, start);
        dest[len] = src % 10 + '0';
    } else {
        dest[start] = src % 10 + '0';
        return start + 1;
    }
    return len + 1;
}

void itoa(int src, char dest[], int max)
{
    int end;
    int start = 0;
    if (src < 0) {
        start = 1;
        dest[0] = '-';
        src *= -1;
    }
    end = itoa_step(src, dest, start);
    dest[end] = '\0';
}