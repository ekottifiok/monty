#include "monty.h"

/**
 * initialize - initialize the all info data list 
 * 
 * @holder: the info list
 * @file: the name of the file
 * Return: int 0 for success and 1 for error
 */
int initialize(all_info *holder, char const *file)
{
	if (!holder)
		return (1);
	holder->file_name = "/home/ifiokekott/VSCode/ALX/monty/bytecodes/00.m";
	return (0);
}

/**
 * main - the entrypoint of the whole program
 *
 * @argc: the number of variadic input
 * @argv: the list that carries the input
 * Return: int 0 for success and 1 for failure
 */
int main(int argc, char const *argv[])
{
	char c;
	all_info data = INFO_INIT;

	
	if (initialize(&data, argv[1]))
		return (1);

	// if (argc != 2 && strcmp(*argv, "monty"))
	// {
	// 	printf("USAGE: monty file\n");
	// 	exit(EXIT_FAILURE);
	// }

	
	if (parse_read(&data))
	{
		exit(EXIT_FAILURE);
	}

	execute_command(&data);
	
	free_all_info(&data);
	exit(EXIT_SUCCESS);
}
