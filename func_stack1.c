#include "monty.h"

/**
 * print_stack - a function that used to adds a node.
 * @stack: top node of the stack pointer.
 * @line_number: opcode line number.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *n_tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	n_tmp = *stack;
	while (n_tmp != NULL)
	{
		printf("%d\n", n_tmp->n);
		n_tmp = n_tmp->next;
	}
}

/**
 * pop_top - A function that used to adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: opcode line number.
 */

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *n_tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);
	n_tmp = *stack;
	*stack = n_tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(n_tmp);
}

/**
 * print_top - A function that used to prints top node.
 * @stack: top node of the stack pointer.
 * @line_number: opcode line number.
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * add_to_stack - a function that used to adds a node.
 * @new_node: new node pointer.
 * @ln: opcode line number.
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *n_tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	n_tmp = head;
	head = *new_node;
	head->next = n_tmp;
	n_tmp->prev = head;
}
