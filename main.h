#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void	_putchar(char c);
int	_printf(const char* format, ...);
void	_printint(int n);
void	_printstring(char* str);
void _print_hex(int n);
void _print_float(float f);

#endif
