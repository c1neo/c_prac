#include <stdio.h>
#include <stdlib.h>

static unsigned int counter;

void increment(void)
{
	counter++;
	printf("%d ", counter);
}

unsigned int retrieve(void)
{
	return counter;
}

int main(void)
{
	printf("current counter: %d\n", retrieve());

	for (int i = 0; i < 5; i++) {
		increment();
	}
	putchar('\n');
	printf("current counter: %d\n", retrieve());

	return EXIT_SUCCESS;
}
