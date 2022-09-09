#include "monty.h"

/**
 * pop_monty - The opcode pop removes the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *buffer;

	if (!stack || !(*stack))
	{	
		fprintf(stderr, "L<%d>: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	buffer = (*stack)->next;
	free(*stack);
	*stack = buffer;

}

/**
 * swap_monty - swaps the top two elements of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	int buffer;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	buffer = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = buffer;

}

/**
 * add_monty - adds the top two elements of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void add_monty(stack_t **stack, unsigned int line_number)
{

	stack_t *buffer;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	(*stack)->next->n += (*stack)->n;
	buffer = (*stack)->next;
	free(*stack);
	*stack = buffer;

}

/**
 * nop_monty - doesn’t do anything.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void nop_monty(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
	
}

/**
 * sub_monty - subtracts the top element of the stack from the second top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void sub_monty(stack_t **stack , unsigned int line_number)
{
	stack_t *buffer;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	(*stack)->next->n -= (*stack)->n;
	buffer = (*stack)->next;
	free(*stack);
	*stack = buffer;
}
