#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct user_input_s - linked list of the user inputs
 * 
 * @line_number: the line number of the command
 * @command: the actual command inputted by the user
 * @next: the next available command
 * 
 * Description: all user input is stored in this list
 */
typedef struct user_input_s
{
	int line_number;
	char *command;
	struct user_input_s *next;
}user_input_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - carries all the instruction
 * 
 */
typedef struct info_s
{	
	instruction_t *instruct;
	user_input_t *input;
	stack_t *stack;
	char const *file_name;
} all_info;

/* custom definitions */
#define STR_TO_INT(val) (val - 48)
#define INT_TO_STR(val) (val + 48)
#define INFO_INIT	{NULL, NULL, NULL, NULL}

user_input_t *add_node_end(user_input_t **head, char *str, int line_num);
int parse_read(all_info *info);
int read_file(char const *file_name, char **file_read);
char *remove_whitespace(char *string);
int free_all_info(all_info *info);
void (*get_builtin_function(char *string))(stack_t **stack, unsigned int line_number);
int execute_command(all_info *info);

void push_monty(stack_t **, unsigned int);
void pall_monty(stack_t **, unsigned int);
void pint_monty(stack_t **, unsigned int);
void pop_monty(stack_t **, unsigned int);
void swap_monty(stack_t **, unsigned int);
void add_monty(stack_t **, unsigned int);
void nop_monty(stack_t **, unsigned int);
void sub_monty(stack_t **, unsigned int);
void div_monty(stack_t **, unsigned int);
void mul_monty(stack_t **, unsigned int);
void mod_monty(stack_t **, unsigned int);
void pchar_monty(stack_t **, unsigned int);
void pstr_monty(stack_t **, unsigned int);


int _strcmp(char *, char *);
char *_strdup(char *);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int len);
char *copy_string_index(char *, unsigned int , char *);
#endif
