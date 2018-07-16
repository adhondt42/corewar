/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 13:25:19 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# define BUFF_SIZE 4

typedef struct		s_proc
{
	int				pos;
	int				carry;
	int				*reg[REG_NUMBER];
	struct s_proc	*next;
}					t_process;

typedef struct		s_board
{
	int				p1_i;
	int				p2_i;
	int				p1_fd;
	int				p2_fd;
	int				cycle;
	t_process		p1_first_proc;
	t_process		p2_first_proc;
	void			*magic_number;
	void			*p1_magic_n;
	void			*p2_magic_n;
	char			*p1_name;
	char			*p2_name;
	char			*p1_comm;
	char			*p2_comm;
	char			*mem_board;

}					t_board;

void      		execute_war(t_board *board);
void            init_f(void (*f[17])(t_board *b, int player));
t_board  		*init_board_data(t_board *board, char **argv);
void			insert_instructions(t_board *board);

/*
 * LIBRARY FILES
 */
int				pos_str_tab(char *haystack, char **needle);
char   			*ft_retcmd(char *str);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_itoa_hex_byte(int value, int upper);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				get_next_line(const int fd, char **line);
void            ft_error(int n);
void            ft_puttable(char *tab);
char			*ft_strcat(char *dest, const char *src);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_chardup(char c);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
int				pos_in_str(char c, char *str);
char			*ft_strcpy(char *dest, const char *str);
void			ft_putstr(char const *s);
int				ft_strcmp(const char *tab, const char *tab2);
char			*ft_strdup(const char *s);
void			*ft_memalloc(size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strlen(const char *src);
void			ft_putnbr(int n);
char			*ft_memalloc_c(size_t size, int c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base, int upper);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_f(char const *s1, char const *s2, int j);

#endif
