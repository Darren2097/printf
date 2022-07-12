#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/**
 * struct types - type structure
 * @p: pointer
 * @func: function
 *
 * Returb : nothing
 */

typedef struct types
{
	char *p;
	int (*func)(va_list);
} print_f;

int _putchar(char c);
int _printf(const char *format, ...);
int (*check_specifier(const char *c))(va_list);
int printc(va_list ar);
int print_str(va_list ar);
int print_perc(va_list ar);
int print_n(va_list ar);

#endif
