#include "main.h"
#include <unistd.h>

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

	while (format[i])
	{
		if (format[i] == '%')
		{
			return (-1);
		}
		else
		{
			write(1,&format[i],1);
			num_char++;
		}
		i++;
	}
	return (num_char);
}
