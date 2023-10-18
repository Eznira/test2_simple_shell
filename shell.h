#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

/**
 * struct builtincommand - Represents a built-in command.
 * @name: The name of the command.
 * @handler: Pointer to the function that handles the command.
 */
typedef struct builtincommand
{
	const char *name;
	void (*handler)(char **args);
} BuiltInCommand;

/* Contstants */
extern const BuiltInCommand builtins[];
extern const int num_builtins;
extern char **environ;

/* Util functions */
ssize_t _getline(char **line_input_ptr, size_t *n, FILE *stream);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);
char * _getenv(const char *env_var);

/* Shell functions */
int get_input(char **input, size_t *input_size);
void tokenize_input(char *input, char **command, char **args);
void exec_builtin(char **args, char *command);
void free_args(char **args);
char *get_cmd_path(char *command);

/* Builtins */
void builtin_cd(char **args);
void builtin_env(char **args);
void builtin_exit(char **args);
void builtin_setenv(char **args);
void builtin_unsetenv(char **args);

#endif /* SHELL_H */
