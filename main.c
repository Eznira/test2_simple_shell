#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	size_t input_size = 0;
	char *input = NULL, *args[MAX_INPUT_SIZE], *command = NULL;
       
	if (argc < 2)
	{
	while (1)
	{
		printf("$ ");
		/* Check for end of file (Ctrl+D) */
		if (get_input(&input, &input_size) == EOF)
		{
			printf(" %s \n", input);
			break;
		}
		if (strlen(input) == 0 || isspace(*input))
			continue;

		/* Tokenize input into command and arguments */
		tokenize_input(input, &command, args);

		/* Find and execute the built-in command */
		exec_builtin(args, command);
	}

	free(input);
	free(command);
	free_args(args);
	} else
	{
		int i;
		command = argv[1];

		for (i = 1; argv[i] != NULL; i++)
			args[i - 1] = argv[i];

		args[i - 1] = NULL;

		exec_builtin(args, command);
	}

	return (0);
}
