#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	size_t input_size = 0;
	char *input = NULL, *args[MAX_INPUT_SIZE], *command = NULL;

	while (1)
	{
		printf("$ ");
		get_input(&input, &input_size);

		/* Check for end of file (Ctrl+D) */
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		if (strlen(input) == 0)
			continue;

		/* Tokenize input into command and arguments */
		tokenize_input(input, &command, args);

		/* Find and execute the built-in command */
		exec_builtin(args, command);
	}

	free(input);
	free(command);
	free_args(args);

	return (0);
}
