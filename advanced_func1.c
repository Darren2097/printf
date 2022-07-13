#include "main.h"
#include <string.h>

/**
 * _bin - converts to binary
 * @binary: ar being passed
 *
 * Return: updated count return
 */

int _bin(va_list binary)
{
	int i, count = 0;
	int *arr;
	unsigned int n = va_arg(binary, unsigned int);
	unsigned int temp = n;

	while (n / 2 != 0)
	{
		n /= 2;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 2;
		temp /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

/**
 * _strrev - prints a reversed string
 * @s: is a pointer to a string
 *
 * Return: void
 **/

void _strrev(va_list *s)
{
	int i, max, half;

	char first, last;

	i = 0;

	while (s[i])
	{
		i++;
	}
	max = i - 1;
	half = max / 2;


	while (half >= 0)
	{
		first = s[max - half];
		last = s[half];
		s[half] = first;
		s[max - half] = last;
		half--;
	}
}


/**
 * _rot13 - prints rot13 version
 * @rot: ar being passed
 *
 * Return: number of chars
 */

int _rot13(va_list rot)
{
	int a, count;
	char *s;

	a = count = 0;
	s = va_arg(rot, char *);

	if (s == NULL)
		return (-1);

	while (s[a] != '\0')
	{
		if ((s[a] >= 'a' && s[a] <= 'z') ||
				(s[a] >= 'A' && s[a] <= 'Z'))
		{
			if ((s[a] >= 'n' && s[a] <= 'z') ||
					(s[a] >= 'N' && s[a] <= 'Z'))
				count = count + _putchar(s[a] - 13);
			else
				count = count + _putchar(s[a] + 13);
		}
		else
			count = count + _putchar(s[a]);
		a++;
	}
	return (count);
}
