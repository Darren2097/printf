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
	return (1);
}

/**
 * print_str - Prints string
 * @ar variadic function
 *
 * Return: number of bytes
 */

int print_str(va_list ar)
{
	char *str = va_arg(ar, char *);
	int k;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (k = 0; str[k] != '\0'; k++)
	{
		_putchar(str[k]);
	}
	return (k);
}

/**
 * print_n - Entry point. Print number
 * @ar: Variable va_list
 *
 * Return: count (nbytes)
 */

int print_n(va_list ar)
{
	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(ar, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;
		while (number / base > 9)
		{
			base *= 10;
		}
		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}

/**
 * print_perc - prints character "%"
 * @ar : arguments
 *
 * Return: character "%"
 */

int print_perc(va_list ar)
{
	(void)ar;
	return (write(1, "%", 1));
}
