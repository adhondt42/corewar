#include "../inc/corewar.h"

void    ft_puttable(char *tab)
{
    int i;

    i = 0;
    while (i != MEM_SIZE)
    {
        ft_putchar(tab[i]);
        if (i != 0 && (i % 2))
            ft_putchar(' ');
        i++;
    }
}