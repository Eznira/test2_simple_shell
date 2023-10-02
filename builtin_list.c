#include "shell.h"

const BuiltInCommand builtins[] = {
	{"cd", builtin_cd},
	{"env", builtin_env},
	{"exit", builtin_exit},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
};

const int num_builtins = sizeof(builtins) /
	sizeof(builtins[0]);
