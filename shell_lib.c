#include "shell.h"

/**
 * get_input - Reads input from stdin and removes newline character
 * @input: Pointer to store the input string
 * @input_size: Pointer to the size of the input string
 *
 * This function reads a line of input from stdin and removes the trailing
 * newline character. It uses getline to dynamically allocate memory for the
 * input string.
 */
int get_input(char **input, size_t *input_size)
{
	int status;

	status = getline(input, input_size, stdin);
	(*input)[strlen(*input) - 1] = '\0';

	return (status);
}

/**
 * tokenize_input - Tokenizes input string into command and arguments
 * @input: Input string to be tokenized
 * @command: Pointer to store the command token
 * @args: Array of pointers to store the argument tokens
 *
 * This function tokenizes the input string based on spaces and stores the
 * command token in the 'command' pointer and argument tokens in the 'args'
 * array of pointers. It uses strtok to perform the tokenization.
 */
void tokenize_input(char *input, char **command, char **args)
{
	int arg_count = 0;
	char *arg;
	*command = strtok(input, " ");
	args[arg_count++] = *command;

	arg = strtok(NULL, " ");
	while (arg != NULL)
	{
		args[arg_count++] = arg;
		arg = strtok(NULL, " ");
	}

	args[arg_count] = NULL;
}
/**
 * exec_builtin - Find and execute builtin commands.
 * @args: command agruments vector.
 * @command: command string
 *
 */
void exec_builtin(char **args, char *command)
{
	int i;

	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(command, builtins[i].name) == 0)
		{
			builtins[i].handler(args);
			break;
		}
	}

		if (i == num_builtins)
		{
			pid_t child_pid = fork();

			if (child_pid < 0)
			{
				perror("Fork failed");
			}
			else if (child_pid == 0)
			{
				execvp(args[0], args);
				perror("Execvp failed");
				exit(1);
			}
			else
			{
				waitpid(child_pid, NULL, 0);
			}
		}
}
/**
 * free_args - frees args
 * @args: The argument vector to be freed.
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
}
