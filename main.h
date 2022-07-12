#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct types
{
	char p;
	int (*func)(va_list);
} print_f;

int _printf(const char *format, ...);
int (*check_specifier(const char x))(va_list);

#endif
