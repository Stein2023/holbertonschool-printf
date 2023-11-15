#include "main.h"

/**
* _printf - print to stout formatted text
* @format: format specifier
* Return: The function
*/
int  _printf(const char *format, ...)
{
        unsigned int i;
        unsigned int str_count;
        unsigned int count = 0;
        va_list args;

        if (!format)
                return (-1);

        va_start(args, format);

        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] != '%')
        {
                main_putchar(format[i]);

                ++count;
        }

                else if (format[i + 1] == 'c')
        {
                main_putchar(va_arg(args, int));

                i++;

                ++count;
        }
                else if (format[i + 1] == 's')
        {

                str_count = putss(va_arg(args, char *));

                i++;

                count += (str_count - 1);

        }
                else if (format[i + 1] == '%')
                {
                main_putchar('%');
                count++;
                i++;


                }
        }
va_end(args);
return (count);
}

