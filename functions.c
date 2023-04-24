#include "main.h"

int	_printstring(char *str)
{
	int len = 0;

	while (*str)
	{
		len = _putchar(*str++);
	}
	return (len);
}

int _print_integer(int value, int base, int uppercase) 
{
	char buffer[32];
	int idx = 0, i, len = 0;
	if (value < 0) {
		len += _putchar('-');
		value = -value;
	}

	do {
		int digit = value % base;
		buffer[idx++] = digit < 10 ? digit + '0' : (uppercase ? 'A' : 'a') + digit - 10;
		value /= base;
	} while (value != 0);

	for (i = idx - 1; i >= 0; i--) {
		len += _putchar(buffer[i]);
	}
	return (len);
}

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

	for (j = i - 1; j >= 0; j--) {
		len += _putchar(buf[j]);
	}
	return (len);
}

int _print_signed(int num, int base)
{
	int len = 0;

	if (num < 0) {
		len += _putchar('-');
		num = -num;
	}
	_print_unsigned(num, base, 0);
	return (len);
}
