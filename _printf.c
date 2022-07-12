#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Function that produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int num_char = 0;
	va_list ar;

	if (format == NULL)
		return (-1);

	va_start(ar, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				return (-1);
			}
			else if (format[i + 1] == '%')
			{
				write(1,'%',1);
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
				write(1,format[i],1);
				num_char++;
			}
		}
		else
		{
			write(1,&format[i],1);
			num_char++;
		}
		i++;
	}
	va_end(ar);
	return (num_char);
}
