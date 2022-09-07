#include "monty.h"

int parse_read(all_info *info)
{
	char *read, *read_cp, *parsed;
	unsigned int iter;
	user_input_t *buffer_uin = NULL;

	if (read_file(info->file_name, &read))
		return (1);
	read_cp = read;
	parsed = strtok(read_cp, "\n");
	for (iter = 0; parsed; iter++)
	{
		add_node_end(&buffer_uin, remove_whitespace(parsed), iter+1);
		parsed = strtok(NULL, "\n");
	}
	info->input = buffer_uin;
    free(read);
	return (0);
}
