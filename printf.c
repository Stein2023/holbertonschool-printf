#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - print to stout formatted text
 * @format: format specifier
 * Return: The function
 */
int _printf(const char *format, ...)
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
			char *str = va_arg(args, char *);

			if (str == NULL)
			{
				str_count = putss("(null)");
			}
			else
			{
				str_count = putss(str);
			}

			i++;

			count += str_count;
		}
		else if (format[i + 1] == '%')
		{
			main_putchar('%');
			count++;
			i++;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			int num = va_arg(args, int);
			char buffer[12];
			snprintf(buffer, sizeof(buffer), "%d", num);

			count += putss(buffer);

			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{

			va_end(args);
			return (-1);
		}
		else
		{

			main_putchar('%');
			count++;
		}
	}

	va_end(args);
	return (count);
}
