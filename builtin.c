/* Contains all built-in functions */
#include "shell.h"

/**
 * builtin_cd - Change the current directory.
 * @args: Array of command arguments.
 */
void builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: missing argument\n");
		return;
	}

	if (chdir(args[1]) != 0)
	{
		perror("cd");
	}
}

/**
 * builtin_env - Display the current environment variables.
 * @args: Array of command arguments.
 */
void builtin_env(char __attribute__((unused)) **args)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
 * builtin_exit - Exit the shell.
 * @args: Array of arguments passed to the exit command.
 *
 * If no argument is provided, the shell will exit with status 0.
 * If an integer argument is provided, the shell will exit with that status.
 * If the provided arg is not a valid int, an error message will be printed.
 */
void builtin_exit(char **args)
{
	if (args[1] != NULL)
	{
		char *endptr;
		int exit_status = (int) strtol(args[1], &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "exit: Invalid argument: %s\n", args[1]);
			return;
		}

		exit(exit_status);
	}
	else
	{
		exit(0);
	}
}

/**
 * builtin_setenv - Initialize a new environment var or modify an existing one.
 * @args: Array of arguments passed to the setenv command.
 *
 * Command syntax: setenv VARIABLE VALUE
 * Prints an error message on stderr on failure.
 */
void builtin_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv: Missing arguments\n");
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * builtin_unsetenv - Remove an environment variable.
 * @args: Array of arguments passed to the unsetenv command.
 *
 * Command syntax: unsetenv VARIABLE
 * Prints an error message on stderr on failure.
 */
void builtin_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv: Missing argument\n");
		return;
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
}
