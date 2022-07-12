#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * check_specifier - specifically checks character type
 * @c: character.
 *
 * Return: pointer
 */

int (*check_specifier(const char *c))(va_list)
{
	print_f printf[] = {
		{'c', printc},
		{'s', print_string},
		{'d', print_n},
		{'i', print_n},
		{NULL, NULL}
	};

	int k;

	for (k = 0; printf[k].p != '\0'; k++)
	{
		if (*c == *(printf[k].p))
		{
			return (printf[k].func);
		}
	}
	return (NULL);
}

/**
 * _printf - Function that produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	int (*func)(va_list);
	va_list ar;

	va_start(ar, format);
	if (format == NULL)
		return (-1);
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				if (format[i + 1] == 'c' && format[i + 1] == 's'
						&& format[i + 1] == '%' && format[i + 1] == 'd'
						&& format[i + 1] == 'i')
				{
					func = check_specifier(&format[i + 1]);
					j += func(ar);
					i++;
				}
				else
				{
					j += _putchar(format[i]);
					j += _putchar(format[i + 1]);
					i++;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			j++;
		}
		i++;
	}
	va_end(ar);
	return (j);
}
