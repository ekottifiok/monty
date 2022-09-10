#include "monty.h"

/**
 * div - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void div_monty(stack_t **stack __attribute__((unused)),
			   unsigned int line_number __attribute__((unused)))
{
	puts("div");
}

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	next->n = next->n * (*stack)->n;
	free(*stack);
	*stack = next;
}

/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{

		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	next->n = next->n % (*stack)->n;
	free(*stack);
	*stack = next;
}

/**
 * pchar - prints the char at the top of the stack
 * followed by a new line.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;

	if (val >= 0 && val <= 127)
	{
		putchar(val);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - print all nodes(value) in the stack
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pstr(stack_t **stack __attribute__((unused)),
				unsigned int line_number __attribute__((unused)))
{
	puts("pstr");
}
