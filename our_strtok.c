#include "shell.h"

int main(void)
{
	char *text[100] = "This is my Simple shell Project";

	text = malloc(sizeof(text));
       	
	printf("Before tokenization, my string is %s\n", text);

	char *get;

	get = strtok(text, " ");

	printf("%s\n", get);
}
	get = strtok(NULL, " ");
	printf("%s\n", get);

	printf("After tokenization twice, my sring is %s\n", text);
{
	return(0);
}	
