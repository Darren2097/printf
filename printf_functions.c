#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes characters
 * @c: variable
 *
 * Return: void
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printc - Prints character
 * @ar: variadic function
 *
 * Return: Always 0 (success)
 */

int printc(va_list ar)
{
	_putchar(va_arg(ar, int));
	return (0);
}

/**
 * print_str - Prints string
 * @s: variadic function
 *
 * Return: number of bytes
 */

int print_str(va_list s)
{
	char *str;
	int k;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (k = 0; str[k] != '\0'; k++)
		{
			write(1, &str[k], 1);
		}
	}
	return (k);
}
