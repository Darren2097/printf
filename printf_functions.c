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
	int len;

	str = va_arg(s, char *);

	if (str == NULL)
	{
		str = "(null)";
		len = 0;
	}
	else
	{
		while (str[len] != '\0')
		{
			len = len + _putchar(str[len]);
		}
	}
	return (len);
}
