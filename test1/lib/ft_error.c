#include "../inc/corewar.h"

void    ft_error(int n)
{
    if (n == 0)
        ft_putstr("Malloc error\n");
    else if (n == 1)
        ft_putstr("argv[1] or argv[2] error\n");
    exit (-1);
}