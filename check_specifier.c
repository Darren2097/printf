#include "main.h"

/**
 * check_specifier - specifically checks character type
 * @c: character.
 *
 * Return: pointer
 */

int (*check_specifier(const char *c))(va_list)
{
	int k;

	print_f printf[] = {
		{'c', printc},
		{'s', print_str},
		{'d', print_n},
		{'i', print_n},
		{NULL, NULL}
	};

	for (k = 0; printf[k].p != '\0'; k++)
	{
		if (*c == *(printf[k].p))
		{
			return (printf[k].func);
		}
	}
	return (NULL);
}
