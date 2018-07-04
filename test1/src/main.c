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

void       init_name_comm(int fd, void **magic_number, char **name, char **comm)
{
    char    str[PROG_NAME_LENGTH + 1];
    char    comment[COMMENT_LENGTH + 1];
    
    *magic_number = ft_memalloc(4);
    // comparer le magic N avec celui de la VM
    read(fd, *magic_number, 4);
    read(fd, str, PROG_NAME_LENGTH);
    str[ft_strlen(str) < PROG_NAME_LENGTH ?
    ft_strlen(str) : PROG_NAME_LENGTH] = '\0';
    lseek(fd, PROG_NAME_LENGTH + 4 + 8, SEEK_SET);
        // + 4 : magicN, +8....? a quoi correspond les 2 octects avant comment
    read(fd, comment, COMMENT_LENGTH);
     comment[ft_strlen(comment) < COMMENT_LENGTH ?
    ft_strlen(comment) : COMMENT_LENGTH] = '\0';
    *name = ft_strdup(str);
    *comm = ft_strdup(comment);
}

t_board    *init_board_data(t_board *board, char **argv)
{
    if (!(board = (t_board *)malloc(sizeof(t_board))))
        ft_error(0);
    board->mem_board = ft_memalloc_c(MEM_SIZE, '0');
    board->p1_fd = open(argv[1], O_RDONLY);
    board->p2_fd = open(argv[2], O_RDONLY);
    if (board->p1_fd == -1 || board->p2_fd == -1)
        ft_error(1);
    init_name_comm(board->p1_fd, &(board->p1_magic_n),
    &(board->p1_name), &(board->p1_comm));
    init_name_comm(board->p2_fd, &(board->p2_magic_n),
    &(board->p2_name), &(board->p2_comm));
    return (board);
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
