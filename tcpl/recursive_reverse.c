/* 
 * K&R Exercise 4-13
 * 04-08-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[], int left, int right);

int main(void)
{
    char s[] = "I can't stop the loneliness";
    printf("%s\n", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);
    return EXIT_SUCCESS;
}

void reverse(char s[], int left, int right)
{
    char c;
    if (left >= right) {
        return;
    }

    c = s[left];
    s[left] = s[right];
    s[right] = c;

    reverse(s, left + 1, right - 1);
}