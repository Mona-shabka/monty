#include "monty.h"

/**
 * mod_nodes - A  function to adds top two elements.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mod");
	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - A function to adds top two elements.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
