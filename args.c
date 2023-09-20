#include <stdio.h>

int main(int argc, char **argv)
{
	printf("ARGC is %d\n", argc);

	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("ARGV[%d] = %s\n", i, argv[i]);
	}

	return(0);
}
