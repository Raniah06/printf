#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        _putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    _putchar('%');
                    count++;
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

