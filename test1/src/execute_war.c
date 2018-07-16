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

#include "../inc/corewar.h"

void        get_instruction(t_board *b)
{
    int             i;
    static char		*cmd_list[17] = {"01", "02", "03", "04", "05", "06", "07",
	    						"08", "09", "0a", "0b", "0c", "0d", "0e", "0f",
		    					"10", NULL};
    void            (*f[17])(t_board *b, int);

    init_f(f);
    i = pos_str_tab(ft_retcmd(b->mem_board + b->p1_i), cmd_list);
    f[i];


}

void       execute_war(t_board *board)
{
    get_instruction(board);
    ft_puttable(board->mem_board);
}