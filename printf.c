#include "main.h"

/**
 * _printf - print to stout formatted text
 * @format: format specifier
 * Return: The function
 */
int _printf(const char *format, ...) {
    unsigned int i;
    unsigned int count = 0;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            main_putchar(format[i]);
            ++count;
        } else {
            ++i;
            if (format[i] == 's') {
                count += putss(va_arg(args, char *));
            } else if (format[i] == 'c') {
                main_putchar(va_arg(args, int));
                ++count;
            } else if (format[i] == '%') {
                main_putchar('%');
                ++count;
            } else {

                main_putchar('%');
                main_putchar(format[i]);
                ++count;
            }
        }
    }

    va_end(args);
    return count;
}

