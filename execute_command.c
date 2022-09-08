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

double str_to_integer(char *s)
{
    unsigned int i, factor, j;
    double pow, digit;

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

int execute_command(all_info *info)
{
    unsigned int iter, iter2;
    user_input_t *user_command;
    char *buffer, *buffer_cp, *parsed;
    int (*builtin_commands)(stack_t **, unsigned int) = NULL;
    stack_t main_stack;
    
    user_command = info->input;
    for (iter = 0; user_command; iter++, user_command = user_command->next)
    {
        buffer = strdup(user_command->command);
        buffer_cp = buffer;
        parsed = strtok(buffer_cp, " ");
        builtin_commands = get_builtin_function(parsed);
        if (!builtin_commands)
        {
            return (user_command->line_number);
        }
        parsed = copy_string_index(user_command->command, 1, " ");
        builtin_commands(&(info->stack), user_command->line_number);
        free(parsed);

        free(buffer);
    }
    return (0);
}