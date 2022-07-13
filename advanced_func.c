#include "main.h"

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
