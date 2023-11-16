#include "main.h"

/**
*  main_putchar
* @c: char input
*
*
Return: 1
*/

int main_putchar(char c)
{
return (write(1, &c, 1));
}
