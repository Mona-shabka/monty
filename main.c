#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - a function that creates a node.
 * @n: Number to go inside the node.
 * Return: node pointer or NULL.
 */

stack_t *create_node(int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		err(4);
	n_node->next = NULL;
	n_node->prev = NULL;
	n_node->n = n;
	return (n_node);
}

/**
 * add_to_queue - a function that used to adds a node.
 * @new_node: new node Pointer.
 * @ln: opcode line number.
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (n_tmp->next != NULL)
		n_tmp = n_tmp->next;

	n_tmp->next = *new_node;
	(*new_node)->prev = n_tmp;

}

/**
 * free_nodes - a function that frees nodes in the stack.
 */

void free_nodes(void)
{
	stack_t *n_tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		n_tmp = head;
		head = head->next;
		free(n_tmp);
	}
}
