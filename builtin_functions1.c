#include "monty.h"

/**
 * div_monty - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void div_monty(stack_t **stack __attribute__((unused)),
			   unsigned int line_number __attribute__((unused)))
{
	puts("div_monty");
}

/**
 * mul_monty - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void mul_monty(stack_t **stack, unsigned int line_number)
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
 * mod_monty - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void mod_monty(stack_t **stack, unsigned int line_number)
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
 * pchar_monty - prints the char at the top of the stack
 * followed by a new line.
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
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
 * pstr_monty - print all nodes(value) in the stack
 * @stack: stack of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */
void pstr_monty(stack_t **stack __attribute__((unused)),
				unsigned int line_number __attribute__((unused)))
{
	puts("pstr_monty");
}
