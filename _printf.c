#include <main.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variadic arguments
 *
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
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        _putchar(*s);
                        s++;
                    }
                    break;
                }
                case '%':
                {
                    _putchar('%');
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            _putchar(*format);
        }

        format++;
    }

    va_end(args);
}
