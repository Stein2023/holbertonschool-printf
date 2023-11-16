#include "main.h"

/**
 * putss - print string
 * @c: string
 * Return: Number of bytes written
 */
int putss(char *c)
{

    int count = 0;

    if (c)
    {
        for (count = 0; c[count] != '\0'; count++)
        {
            main_putchar(c[count]);
        }
    }
    else {
        char *null_str = "(null)";
        for (count = 0; null_str[count] != '\0'; count++) 
	{
            main_putchar(null_str[count]);
        }
    }

    return (count);
}
