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
    int printed = 0;

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
                    printed++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        _putchar(*s);
                        s++;
                        printed++;
                    }
                    break;
                }
                case '%':
                {
                    _putchar('%');
                    printed++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char buffer[12];
                    int len = snprintf(buffer, sizeof(buffer), "%d", num);
                    for (int i = 0; i < len; i++) {
                        _putchar(buffer[i]);
                        printed++;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            _putchar(*format);
            printed++;
        }

        format++;
    }

    va_end(args);
    return printed;
}

