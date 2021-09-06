#include "minitalk.h"

void    error(char *s)
{
    if (s)
        ft_printf("\n%s\n", s);
    exit(EXIT_FAILURE);
}