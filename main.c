#include "shell.h"
/**
 * non_iteractive - Runs the shell in non interactive mode
 *
 * @argv: The argument vector passed to main.
 * @command: The command string to be executed.
 * @args: The list of arguements.
 */
void non_interactive(char *argv[], char **command, char **args)
{
	int i; char *full_command;

	*command = argv[1];
	full_command = get_cmd_path(*command);

	for (i = 1; argv[i] != NULL; i++)
		args[i - 1] = argv[i];

	args[i - 1] = NULL;

	if (!full_command)
	{
		printf("Error: command not found!\n");

      }
	else
		exec_builtin(args, *command);
	free(full_command);
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	size_t input_size = 0;
	char *input = NULL, *full_command, *args[MAX_INPUT_SIZE], *command = NULL;

	if (argc < 2)
	{
		while (1)
		{
			printf("$ ");

			if (get_input(&input, &input_size) == EOF)
			{
				break;
			}

			if (strlen(input) == 0 || isspace(*input))
				continue;

			tokenize_input(input, &command, args);
			printf("%s %s\n", command, full_command);
			full_command = get_cmd_path(command);
			printf("%s %s\n", command, full_command);
			
			if (!full_command)
			{
				printf("Error: command not found!\n");
				continue;
			}
			else
			{
				exec_builtin(args, command);
				free(full_command);
			}
		}
		free(input);
	}
	else
		non_interactive(argv, &command, args);

	return (0);
}
