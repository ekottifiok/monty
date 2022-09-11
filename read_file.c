#include "monty.h"

/**
 * read_file - reads what's inside a file
 *
 * @file_name: the file name to be read
 * @file_read: where to store the file that has being read
 * Return: int 0 for success and 1 for failure
 */
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
		if (c == '$')
		{
			iter--;
			continue;
		}
		buffer[iter] = c;
		buffer = realloc(buffer, sizeof(char) * (iter + 2));
	}
	fclose(fp);
	buffer[iter] = '\0';
	*file_read = buffer;
	return (0);
}
