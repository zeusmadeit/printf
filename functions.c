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


