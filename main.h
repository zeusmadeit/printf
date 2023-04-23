#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	_putchar(char c);
int	_printstring(char *str);
int	_print_integer(int value, int base, int uppercase);
int	_power(int base, int exp);
int	_num_digits(int num);
int	_reverse(char *str, int len);
int	_itoa(int num, char *str);
int	_print_float(double value, int precision);
int	_printf(const char *format, ...);

#endif
