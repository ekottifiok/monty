#include "monty.h"

/**
 * push - add a node(value) at the top of the stack
 * @top: current top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode, *buffer, *head = *stack;

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

    newNode->next = *stack;
    *stack = newNode;
}

/**
 * pall - print all nodes(value) in the stack
 * @top: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
    stack_t *curr;

    (void)line_number;

    if (!stack)
        return;

    curr = *stack;

    while (curr)
    {
        printf("%d\n", (curr)->n);
        curr = curr->next;
    }
}
void pint_monty(stack_t **stack, unsigned int line_number)
{
    puts("pint_monty");
}
void pop_monty(stack_t **stack, unsigned int line_number)
{
    puts("pop_monty");
}
void swap_monty(stack_t **stack, unsigned int line_number)
{
    puts("swap_monty");
}
void add_monty(stack_t **stack, unsigned int line_number)
{
    puts("add_monty");
}
void nop_monty(stack_t **stack, unsigned int line_number)
{
    puts("nop_monty");
}
void sub_monty(stack_t **stack, unsigned int line_number)
{
    puts("sub_monty");
}
void div_monty(stack_t **stack, unsigned int line_number)
{
    puts("div_monty");
}
void mul_monty(stack_t **stack, unsigned int line_number)
{
    puts("mul_monty");
}
void mod_monty(stack_t **stack, unsigned int line_number)
{
    puts("mod_monty");
}
void pchar_monty(stack_t **stack, unsigned int line_number)
{
    puts("pchar_monty");
}
void pstr_monty(stack_t **stack, unsigned int line_number)
{
    puts("pstr_monty");
}

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
        if (!_strcmp(functions[iteration].opcode, string) || !_strncmp(functions[iteration].opcode, string, _strlen(string) - 1))
            break;
    }

    return (functions[iteration].f);
}