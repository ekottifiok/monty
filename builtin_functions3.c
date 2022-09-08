#include "monty.h"

/**
 * push_monty - add a node(value) at the top of the stack
 * @stack: current top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

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
 * pall_monty - print all nodes(value) in the stack
 * @stack: top of the stack
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

/**
 * pint_monty - print all nodes(value) in the stack
 * @stack: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pint_monty(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
	puts("pint_monty");
}
