/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 13:26:26 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int	main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr("./a.out [number][base]\n");
        return (0);
    }    
    ft_putstr(ft_itoa_base(ft_atoi(argv[1]), ft_atoi(argv[2]), 1));
    ft_putchar('\n');
    return (0);
}
