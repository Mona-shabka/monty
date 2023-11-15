#include "monty.h"

/**
 * print_str - A function to prints a string.
 * @stack: top node of the stack pointer.
 * @ln: opcode line number.
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *n_tmp;
	int n_ascii;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	n_tmp = *stack;
	while (n_tmp != NULL)
	{
		n_ascii = n_tmp->n;
		if (n_ascii <= 0 || n_ascii > 127)
			break;
		printf("%c", n_ascii);
		n_tmp = n_tmp->next;
	}
	printf("\n");
}

/**
 * rotl - A function to rotates the first node to the bottom.
 * @stack: top node stack pointer.
 * @ln: opcode line number.
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *n_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	n_tmp = *stack;
	while (n_tmp->next != NULL)
		n_tmp = n_tmp->next;
	n_tmp->next = *stack;
	(*stack)->prev = n_tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - A function to rotates last node to the top.
 * @stack: top node stack pointer.
 * @ln: opcode line number.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *n_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	n_tmp = *stack;
	while (n_tmp->next != NULL)
		n_tmp = n_tmp->next;
	n_tmp->next = *stack;
	n_tmp->prev->next = NULL;
	n_tmp->prev = NULL;
	(*stack)->prev = n_tmp;
	(*stack) = n_tmp;
}

/**
 * print_char - A function to prints the Ascii value.
 * @stack: top node stack pointer.
 * @line_number: opcode line number.
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int n_ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);
	n_ascii = (*stack)->n;
	if (n_ascii < 0 || n_ascii > 127)
		string_err(10, line_number);
	printf("%c\n", n_ascii);
}
