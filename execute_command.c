#include "monty.h"

/**
 * _pow_recursion - finds the power of number using recursion
 * @x: the base value example 10
 * @y: the power example 2
 * Return: returns the value of 10**2 which is 100
 */
double _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

/**
 * str_to_integer - converts string to integer
 *
 * @s: the string to be converted
 * Return: double of the result
 */
double str_to_integer(char *s)
{
	unsigned int i, factor;
	double digit;

	if (!s)
		return (-1);
	factor = strlen(s);
	for (i = 0, digit = 0, factor--; s[i]; i++, factor--)
	{
		if (s[i] < '0' || s[i] > '9')
			break;
		digit += STR_TO_INT(s[i]) * _pow_recursion(10, factor);
	}
	return (digit);
}

/**
 * execute_command - the main brain behind the whole process
 *
 * @info: the info holder
 * Return: int 0 for success and unsigned int for line of failure
 */
int execute_command(all_info *info)
{
	unsigned int iter;
	user_input_t *user_command;
	char *buffer, *buffer_cp, *parsed;
	void (*builtin_commands)(stack_t **, unsigned int) = NULL;

	user_command = info->input;
	for (iter = 0; user_command; iter++, user_command = user_command->next)
	{
		buffer = _strdup(user_command->command);
		buffer_cp = buffer;
		parsed = strtok(buffer_cp, " ");
		builtin_commands = get_builtin_function(parsed);
		if (!builtin_commands)
		{
			return (user_command->line_number);
		}
		parsed = copy_string_index(user_command->command, 1, " ");
		if (!parsed)
			parsed = 0;
		builtin_commands(&(info->stack), atoi(parsed));
		free(parsed);

		free(buffer);
	}
	return (0);
}
