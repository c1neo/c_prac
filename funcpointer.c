#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
	printf("Called function 1\n");
}

void func2(void)
{
	printf("Called function 2\n");
}

void func3(void)
{
	printf("Called function 3\n");
}

int main(int argc, char *argv[])
{
	void (*func[3])(void) = {
		func1,
		func2,
		func3
	};

	func[1]();

	return EXIT_SUCCESS;
}
