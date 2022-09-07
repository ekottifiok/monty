#include "monty.h"

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

int free_all_info(all_info *info)
{
    unsigned int iter;

    free_user_input(&info->input);
    return (0);
}