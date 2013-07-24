#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int i=10; i > 0; --i)
	{
		printf("%-5d", i);
		printf("Hello %s\n", argv[1]);
	}

	return 0;
}
