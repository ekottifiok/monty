#include "monty.h"

/**
 * push - add a node(value) at the top of the stack
 * @stack: current top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
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
	newNode->next->prev = newNode;
	*stack = newNode;
}

/**
 * pall - print all nodes(value) in the stack
 * @stack: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
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
 * pint - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *buffer, *head;
	unsigned int i;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	head = *stack;
	buffer = (*stack)->next;
	buffer->prev = NULL;
	head->next = NULL;

	*stack = buffer;
	while (buffer->next)
		buffer = buffer->next;

	buffer->next = head;
	head->prev = buffer;
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *buffer, *head;
	unsigned int i;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	buffer = *stack;
	while (buffer->next)
		buffer = buffer->next;
	buffer->next = *stack;
	(*stack)->prev = buffer;
	*stack = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
