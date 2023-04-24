#include "main.h"
/**
 * _printf_rot13 - printf str to ROT13 place into buffer
 * @args: type struct va_arg where is allocated printf arguments
 * Return: counter
 *
 */
int _printf_rot13(va_list args)
{
	int i, j, counter = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; alpha[j] && !k; j++)
		{
			if (s[i] == alpha[j])
			{
				_putchar(beta[j]);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[i]);
			counter++;
		}
	}
	return (counter);
}

/**
* _non_printable_char - prints Non printable characters (0 < ASCII value < 32 or >= 127)
* are printed this way: \x, followed by the ASCII code value in
* hexadecimal (upper case - always 2 characters)
*/
int _non_printable_char(va_list args)
{
	int i = 0, count = 0, num;
	char *s = va_arg(args, char*);

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			num = (int) s[i];
			count += _print_unsigned(num, 16, 1);
		}
		else
		{
			count += _putchar(s[i]);
		}
	}
	return (count);
}

