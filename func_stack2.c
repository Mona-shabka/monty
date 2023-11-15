#include "monty.h"

/**
 * swap_nodes - a function swaps the top two elements.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *n_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	n_tmp = (*stack)->next;
	(*stack)->next = n_tmp->next;
	if (n_tmp->next != NULL)
		n_tmp->next->prev = *stack;
	n_tmp->next = *stack;
	(*stack)->prev = n_tmp;
	n_tmp->prev = NULL;
	*stack = n_tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - A function to adds top two elements.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "sub");
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - A function to dds top two elements.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int n_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");
	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	n_sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = n_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing.
 * @stack: stack top node pointer.
 * @line_number: Opcode line number.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
