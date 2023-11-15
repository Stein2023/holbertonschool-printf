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

    return (count);
}




