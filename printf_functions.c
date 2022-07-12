#include "main.h"
#include <stdarg.h>

/**
 * printc - Prints character
 * @ar: variadic function
 *
 * Return: Always 0 (success)
 */

int printc(va_list ar)
{
	write(1,va_arg(ar, int), 1);
	return (0);
}

/**
 * print_str - Prints string
 * @s: variadic function
 *
 * Return: Always 0 (success)
 */

int print_str(va_list s)
{
	char *str;
	int k;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		for (k = 0; str[k] != '\0'; k++)
		{
			write(1, str[k], 1);
		}
	}
	return (k);
}
