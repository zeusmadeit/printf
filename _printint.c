#include "main.h"

/**
 * _printint - prints an integer
 * @n; int
 */
void	printint(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		_printint(n/10);
	}
	_putchar(n%10 + '0');
}
