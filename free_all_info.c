#include "monty.h"

/**
 * free_user_input - frees the user_input list
 *
 * @holder: the user_input list to be freed
 */
void free_user_input(user_input_t **holder)
{
	user_input_t *buffer;

	if (!holder)
		return;

	while (*holder)
	{
		buffer = (*holder)->next;
		free((*holder)->command);
		free(*holder);
		*holder = buffer;
	}
	*holder = NULL;
}

/**
 * free_stack - the stack that carries all work
 *
 * @holder: the holder of the stack
 */
void free_stack(stack_t **holder)
{
	stack_t *buffer;

	if (!holder)
		return;

	while (*holder)
	{
		buffer = (*holder)->next;
		free(*holder);
		*holder = buffer;
	}
	*holder = NULL;
}

/**
 * free_all_info - frees everything that needs to be freed
 *
 * @info: the all info list to be freed
 * Return: int 0 for success and
 */
int free_all_info(all_info *info)
{
	free_user_input(&info->input);
	free_stack(&info->stack);
	return (0);
}
