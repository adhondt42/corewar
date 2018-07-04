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

t_board    *init_board_data(t_board *board, char **argv)
{
    char    str[PROG_NAME_LENGTH + 1];
    char    comm[COMMENT_LENGTH + 1];
    int     ret;
    int     i;

    ret = 0;
    i = 0;
    if (!(board = (t_board *)malloc(sizeof(t_board))))
        ft_error(0);
    board->mem_board = ft_memalloc_c(MEM_SIZE, '0');
    board->p1_magic_n = ft_memalloc(4);
    board->p2_magic_n = ft_memalloc(4);
    board->p1_fd = open(argv[1], O_RDONLY);
    board->p2_fd = open(argv[2], O_RDONLY);
    if (board->p1_fd == -1 || board->p2_fd == -1)
       ft_error(1);
    
    read(board->p1_fd, str, 4);
    board->p1_magic_n = ft_memcpy(board->p1_magic_n, str, 4);
    // comparer le magic N avec celui de la VM
    read(board->p1_fd, str, PROG_NAME_LENGTH);
    str[ft_strlen(str) < PROG_NAME_LENGTH ?
    ft_strlen(str) : PROG_NAME_LENGTH] = '\0';
    lseek(board->p1_fd, PROG_NAME_LENGTH + 4 + 8, SEEK_SET);
    // + 4 : magicN, +8....? a quoi correspond les 2 octects avant comment
    read(board->p1_fd, comm, COMMENT_LENGTH);
     comm[ft_strlen(comm) < COMMENT_LENGTH ?
    ft_strlen(comm) : COMMENT_LENGTH] = '\0';
    board->p1_name = ft_strdup(str);
    board->p1_comment = ft_strdup(comm);
    ft_putstr(str);
    ft_putstr("\n");
    ft_putstr(comm);
    return (NULL);
}

int	main(int argc, char **argv)
{
    t_board  *board;

    if (argc != 3)
    {
        ft_putstr("Need 3 args\n");
        exit (0);
    };
    board = init_board_data(board, argv);
    return (0);
}
