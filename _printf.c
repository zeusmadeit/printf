#include "main.h"

/**
 * _printf - produces output according to a format
 * and prints it to the stdout
 * @format: the format given
 * @...: ellipsis to indicate this is a variadic function
 * Return: returns lemgth of printed characters
*/

int	_printf(const char *format, ...)
{
	int written;
	va_list args;
	int short_flag;
	int long_flag;

	va_start(args, format);
	written = 0;
	short_flag = 0;
	long_flag = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'l')
			{
				long_flag = 1;
				++format;
			}
			else if (*format == 'h')
			{
				short_flag = 1;
				++format;
			}

			switch (*format)
			{
				case 'd':
				case 'i':
					{
						int value = (long_flag ? va_arg(args, long) : (short_flag ? (short)va_arg(args, int) : va_arg(args, int)));
						written += _print_integer(value, 10, 0);
						break;
					}

				case 'u':
				case 'o':
				case 'b':
				case 'x':
				case 'X':
					{
						int base = (*format == 'o') ? 8 : ((*format == 'x' || *format == 'X') ? 16 : ((*format == 'b') ? 2 : 10));
						int uppercase = (*format == 'X') ? 1 : 0;
						unsigned int value = (long_flag ? va_arg(args, unsigned long) : (short_flag ? (unsigned short)va_arg(args, unsigned int) : va_arg(args, unsigned int)));
						written += _print_integer(value, base, uppercase);
						break;
					}

				case 'c':
					{
						char c = (char) va_arg(args, int);
						written += _putchar(c);
						break;
					}

				case '%':
					{
						written += _putchar(37);
						break;
					}

				case 's':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						written += _printstring(str);
						break;
					}

				default:
					{
						write(1, format-1, 2);
						written += 2;
						break;
					}
			}
		}
		else
		{
			written += -_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (written);
}
