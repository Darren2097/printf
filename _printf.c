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

	while (format[i])
	{
		write(1,&format[i],1);
		i++;
	}
	return (0);
}
