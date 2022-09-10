#include "monty.h"

/**
 * get_builtin_function - Get the builtin function object
 *
 * @string: string to be compared
 * Return: function if found and null if not
 */
void (*get_builtin_function(char *string))(stack_t **, unsigned int)
{
	unsigned int iteration;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_monty},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	for (iteration = 0; functions[iteration].opcode != NULL; iteration++)
	{
		if (!_strcmp(functions[iteration].opcode, string))
			break;
	}

	return (functions[iteration].f);
}
