#include "monty.h"

/**
 * is_int - checks if a string is valid for atoi
 * @str: the string
 *
 * Return: 1 for true, 0 for false
 */
int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (*str == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
