#include "main.h"

int _power(int base, int exp)
{
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

int _num_digits(int num)
{
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int _reverse(char *str, int len)
{
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return len;
}

int _itoa(int num, char *str)
{
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num /= 10;
    }
    int len = i;
    _reverse(str, len);
    str[i] = '\0';
    return len;
}

int _print_float(double value, int precision)
{
    if (value < 0) {
        write(1, "-", 1);
        value = -value;
    }

    int integer_part = (int) value;
    double fractional_part = value - integer_part;

    int int_len = _num_digits(integer_part);
    int frac_len = precision;

    char int_str[int_len + 1];
    char frac_str[frac_len + 1];

    int int_digits = _itoa(integer_part, int_str);

    write(1, int_str, int_digits);

    if (precision != 0) {
        write(1, ".", 1);

        int i = 0;
        while (i < precision) {
            fractional_part *= 10;
            int frac_digit = (int) fractional_part;
            frac_str[i++] = frac_digit + '0';
            fractional_part -= frac_digit;
        }
        int frac_digits = i;
        write(1, frac_str, frac_digits);
    }

    return int_digits + 1 + frac_len;
}

