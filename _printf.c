#include "main.h"
#include <stdarg.h>

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
	if (format == NULL || !format[i + 1])
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
