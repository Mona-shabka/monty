#include "monty.h"

/**
 * read_file - a function that used to reads a file.
 * @fd: file descriptor pointer.
 * Return: void.
 */

void read_file(FILE *fd)
{
	int n_format = 0;
	size_t n_len = 0;
	char *buffer = NULL;
	int line_number;

	for (line_number = 1; getline(&buffer, &n_len, fd) != -1; line_number++)
	{
		n_format = parse_line(buffer, line_number, n_format);
	}
	free(buffer);
}

/**
 * parse_line - a function that separates line into function.
 * @buffer: line from the file.
 * @line_number: line number.
 * @format:  storage format. If 0 Nodes as a stack.
 * if 1 nodes as a queue.
 * Return: Returns 0 if stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *n_value;
	const char *n_delim = "\n ";
	char *n_opcode;

	if (buffer == NULL)
		err(4);
	n_opcode = strtok(buffer, n_delim);
	if (n_opcode == NULL)
		return (format);
	n_value = strtok(NULL, n_delim);
	if (strcmp(n_opcode, "stack") == 0)
		return (0);
	if (strcmp(n_opcode, "queue") == 0)
		return (1);
	find_func(n_opcode, n_value, line_number, format);
	return (format);
}

/**
 * find_func - a function that find function for the opcode.
 * @opcode: opcode.
 * @value: argument of opcode.
 * @format:  storage format. If 0 Nodes as a stack.
 * @ln: line number.
 * if 1 nodes will be entered as a queue.
 * Return: void.
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int n_flag;
	int n;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (n_flag = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			call_fun(func_list[n].f, opcode, value, ln, format);
			n_flag = 0;
		}
	}
	if (n_flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - A function that calls the required function.
 * @func: called function pointer.
 * @op: string opcode.
 * @val: string.
 * @ln: line numeber.
 * @format: Format specifier. If 0 Nodes as a stack.
 * if 1 nodes as a queue.
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	int n_flag;
	int m;
	stack_t *n_node;

	n_flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			n_flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (m = 0; val[m] != '\0'; m++)
		{
			if (isdigit(val[m]) == 0)
				err(5, ln);
		}
		n_node = create_node(atoi(val) * n_flag);
		if (format == 0)
			func(&n_node, ln);
		if (format == 1)
			add_to_queue(&n_node, ln);
	}
	else
		func(&head, ln);
}

/**
 * open_file - a function that used to opens a file.
 * @file_name: file namepath.
 * Return: void.
 */

void open_file(char *file_name)
{
	FILE *n_fd = fopen(file_name, "r");

	if (file_name == NULL || n_fd == NULL)
		err(2, file_name);
	read_file(n_fd);
	fclose(n_fd);
}
