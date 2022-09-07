#include "monty.h"


int read_file(char const *file_name, char **file_read)
{
	char c, *buffer;
	FILE *fp;
	unsigned int iter;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		return (1);
	}
	buffer = malloc(sizeof(char));
	for (iter = 0; (c = fgetc(fp)) != EOF; iter++)
	{

		buffer[iter] = c;
		buffer = realloc(buffer, sizeof(char) * (iter+2));
	}
	fclose(fp);
	buffer[iter] = '\0';
	*file_read = buffer;
	return (0);
}
