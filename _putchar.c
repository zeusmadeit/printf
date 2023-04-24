#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a char to stdout
 * @c: the character to be printed
 * Reurn: nothing
 */
int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
