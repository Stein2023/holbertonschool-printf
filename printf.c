#include "main.h"

/**
 * _printf - print to stout formatted text
 * @format: format specifier
 * Return: The function
 */
int _printf(const char *format, ...)
{
	unsigned int i, str_count;
	int count = 0;
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
			count += str_count;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			int num = va_arg(args, int);
			count += print_number(num);
			i++;
		}
		else if (format[i + 1] == '%')
		{
			main_putchar('%');
			++count;
			i++;
		}
		else
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);



	return (count);
}

#include "main.h"

/**
 * main_putchar - putchar function.
 * @c: char input
 *
 * Return: 1.
*/
int main_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - print an integer.
 * @num: integer.
 * Return: The number of digits printed.
 */
int print_number(int num)
{
	int count = 0;
	
	if (num < 0)
	{
		main_putchar('-');
		num = -num;
		++count;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	main_putchar(num % 10 + '0');
	return (count + 1);
}


