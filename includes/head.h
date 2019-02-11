/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 18:11:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../../libft/libft.h"

#  define C_RED			write(1, "\x1b[31m", 5);
#  define C_GREEN		write(1, "\x1b[32m", 5);
#  define C_BLUE		write(1, "\x1b[34m", 5);
#  define C_YELLOW		write(1, "\x1b[33m", 5);
#  define C_BLUE		write(1, "\x1b[34m", 5);
#  define C_MAGENTA		write(1, "\x1b[35m", 5);
#  define C_CYAN		write(1, "\x1b[36m", 5);
#  define C_RESET		write(1, "\x1b[0m", 5);
#  define C_BROWN		write(1, "\x1b[38;2;238;205;163m", 19);
#  define C_PINK		write(1, "\x1b[38;2;239;100;100m", 19);
#  define C_PURPLE		write(1, "\x1b[38;2;101;78;163m", 18);
#  define C_ORANGE		write(1, "\x1b[38;2;155;75;43m", 17);
#  define C_TURQUOISE	write(1, "\x1b[38;2;68;140;121m", 18);
#  define CURSOR_RESET	write(1, "\033[0;0H", 6);
#  define CURSOR_LOAD	write(1, "\033[u", 3);
#  define CURSOR_SAVE	write(1, "\033[s", 3);
#  define CLEAR_SCREEN	write(1, "\033[2J", 4);

typedef struct		s_push_swap
{
	int				*stack_a;
	int				*stack_b;
	char			*instruction;
	size_t			all;
	size_t			size_a;
	size_t			size_b;
	int				count;
}					t_push_swap;

int		**setup_tab(int ac, char **av);
int		is_it_good(int **to_order, size_t size);
int		print_push_swap(t_push_swap *push);
int		lets_play(int **to_order, size_t size);


#endif
