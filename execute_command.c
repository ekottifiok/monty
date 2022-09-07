#include "monty.h"

int execute_command(all_info *info)
{
    unsigned int iter, iter2;
    user_input_t *user_command;
    char *buffer, *buffer_cp, *parsed;
    
    user_command = info->input;
    for (iter = 0; user_command;iter++, user_command = user_command->next)
    {
        buffer = strdup(user_command->command);
        buffer_cp = buffer;
        parsed = strtok(buffer_cp, " ");
        for (iter2 = 0; parsed; iter2++)
        {
            parsed = strtok(NULL, " ");
        }
        free(buffer);
    }
    return (0);
}