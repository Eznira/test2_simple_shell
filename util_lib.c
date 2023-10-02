#include "shell.h"

/**
 * _getline - Read a line from a file stream.
 * @line_input_ptr: Pointer to the buffer that will store the input line.
 * @n: Pointer to the size of the buffer.
 * @stream: The file stream to read from.
 *
 * This function reads a line from the provided file stream and stores it in
 * a dynamically allocated buffer. The buffer size is increased as needed to
 * accommodate the entire line.
 *
 * Return: The number of characters read, excluding the null-terminator.
 *         -1 if an error occurs.
 */
ssize_t _getline(char **line_input_ptr, size_t *n, FILE *stream)
{
	int c, buff_size = 1024;
	int index = 0;
	char *buffer = (char *)malloc(buff_size * sizeof(char));

	if (!buffer)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			buffer[index] = '\0';
			break;
		} else if (c == '\n')
		{
			buffer[index] = c;
			break;
		}

		buffer[index] = c;
		index++;

	}

	*line_input_ptr = buffer;
	*n = buff_size;
	return ((ssize_t)index);
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: Pointer to the string to search
 * @c: Character to locate
 *
 * Return: Pointer to the first occurrence of @c in @s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (0);
}

/**
 * _strtok - Tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter characters
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, char *delim)
{
	static char *_token;
	char *token_start = _token;

	if (str != NULL)
	{
		_token = str;
	}

	while (*_token != '\0' && _strchr(delim, *_token) != NULL)
	{
		_token++;
	}

	if (*_token == '\0')
	{
		return (NULL);
	}

	token_start = _token;
	while (*_token != '\0' && _strchr(delim, *_token) == NULL)
	{
		_token++;
	}

	if (*_token != '\0')
	{
		*_token = '\0';
		_token++;
	}

	return (token_start);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return:
 *   0 if the strings are equal
 *   a negative value if s1 is less than s2
 *   a positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (s1[i] - s2[i]);
}
