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
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{NULL, NULL}};

	for (iteration = 0; functions[iteration].opcode != NULL; iteration++)
	{
		if (!_strcmp(functions[iteration].opcode, string) ||
			!_strncmp(functions[iteration].opcode, string, _strlen(string) - 1))
			break;
	}

	return (functions[iteration].f);
}
