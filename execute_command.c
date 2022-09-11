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
	for (factor = 0, i = 0; s[i] && (s[i] >= '0' && s[i] <= '9'); i++, factor++)
	;
	for (i = 0, digit = 0, factor--; s[i]; i++, factor--)
	{
		if (s[i] < '0' || s[i] > '9')
			return (digit);
		digit += STR_TO_INT(s[i]) * _pow_recursion(10, factor);
	}
	return (digit);
}

/**
 * push_queue - add a node(value) at the top of the stack
 * @stack: current top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode, *buffer = *stack;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = line_number;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (!(*stack))
	{
		*stack = newNode;
		return;
	}
	while (buffer->next)
		buffer = buffer->next;
	newNode->prev = buffer;
	buffer->next = newNode;
}

/**
 * execute_command - the main brain behind the whole process
 *
 * @info: the info holder
 * Return: int 0 for success and unsigned int for line of failure
 */
int execute_command(all_info *info)
{
	unsigned int iter, stack_queue = 0;
	user_input_t *user_command = info->input;
	char *buffer = _strdup(user_command->command), *buffer_cp = buffer, *parsed;
	void (*builtin_commands)(stack_t **, unsigned int) = NULL;

	for (iter = 0; user_command; iter++, user_command = user_command->next)
	{
		parsed = strtok(buffer_cp, " ");
		if (stack_queue && !_strncmp(parsed, "push", 4))
		{
			parsed = copy_string_index(user_command->command, 1, " ");
			push_queue(&(info->stack), (unsigned int)str_to_integer(parsed));
			free(parsed);
		}
		else if (!_strcmp(parsed, "stack"))
		{
			stack_queue = 0;
		}
		else if (!_strcmp(parsed, "queue"))
		{
			stack_queue = 1;
		}
		else
		{
			builtin_commands = get_builtin_function(parsed);
			if (!builtin_commands)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						user_command->line_number, user_command->command);
				exit(EXIT_FAILURE);
			}
			parsed = copy_string_index(user_command->command, 1, " ");
			if (parsed == NULL)
				builtin_commands(&(info->stack), user_command->line_number);
			builtin_commands(&(info->stack), (unsigned int)str_to_integer(parsed));
			free(parsed);
		}
	}
	free(buffer);
	return (0);
}
