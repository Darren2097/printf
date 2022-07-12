#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * check_specifier - specifically checks character type
 * @x: character.
 *
 * Return: 0 when successful
 */

int (*check_specifier(const char x))(va_list)
{
	print_f printf[] = {
		{'c', printc},
		{'s', print_string},
		{'\0', NULL}
		};

	int j;

	for (j = 0; printf[j].p != '\0'; j++)
	{
		if (printf[j].p == x)
		{
			return (printf[j].func);
		}
	}

	return (0);
}

/**
 * _printf - Function that produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, num_char = 0;
	va_list ar;

	if (format == NULL)
		return (-1);

	va_start(ar, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			else if (format[i + 1] == '%')
			{
				write(1, '%', 1);
				num_char++;
				i++;
			}
			else if ((check_specifier(format[i + 1])) != NULL)
			{
				num_char += (check_specifier(format[i + 1]))(ar);
				i++;
			}
			else
			{
				write(1, &format[i], 1);
				num_char++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			num_char++;
		}
		i++;
	}
	va_end(ar);
	return (num_char);
}
