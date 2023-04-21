#include "main.h"

/**
 * _printstring - prints the given string
 * @str: string to be printed
 */
void	_printstring(char* str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
