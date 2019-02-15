/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/15 13:43:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../../libft/libft.h"

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
