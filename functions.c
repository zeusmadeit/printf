#include "main.h"

/**
 * _printstring - A function that prints a string
 * @str: the string to be printed
 *
 * Return: 0
 */

int _printstring(char *str)
{
	int len = 0;

	while (*str)
	{
		len = _putchar(*str++);
	}
	return (len);
}

/**
 * _print_integer - A function that prints an integer
 * @value: The int value to be prnted
 * @base: Represents the numeric base to be used
 * @uppercase: representing whether uppercase letters should be used
 * Return: 0
 */

int _print_integer(int value, int base, int uppercase)
{
	char buffer[32];
	int idx = 0, i, len = 0;

	if (value < 0}
	{
		len += _putchar('-');
		value = -value;
	}

	do {
		int digit = value % base;

		buffer[idx++] = digit < 10 ? digit + '0' : (uppercase ? 'A' : 'a') + digit - 10;
		value /= base;
	} while (value != 0);

	for (i = idx - 1; i >= 0; i--)
	{
		len += _putchar(buffer[i]);
	}
	return (len);
}

/**
 * _print_unsigned - a function that prints an unsigned int
 * @num: the integer to be printed
 * @base: Base to be used for printing
 * @uppercase: a flag that indicates if an uppercase should be used
 *
 * Return: 0
 */

int _print_unsigned(unsigned int num, int base, int uppercase)
{
	char *digits;
	char buf[32];
	int i = 0, j, len = 0;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	do {
		buf[i++] = digits[num % base];
		num /= base;
	} while (num != 0);

	for (j = i - 1; j >= 0; j--)
	{
		len += _putchar(buf[j]);
	}
	return (len);
}

/**
 * _print_signed - a function that prints a signed int in the given base
 * @num: The signed integer to be printed
 * @base: The base in which the integer is to be printed
 * Return: 0
 */

int _print_signed(int num, int base)
{
	int len = 0;

	if (num < 0)
	{
		len += _putchar('-');
		num = -num;
	}
	_print_unsigned_int(num, base, 0);
	return (len);
}

/**
 * _printf_srev - function that prints a str in reverse
 * @args: type struct va_arg where is allocated printf arguments
 *
 * Return: the string
 */
int _printf_srev(va_list args)
{
	char *s = va_arg(args, char*);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
