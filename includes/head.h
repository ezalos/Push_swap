/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:30:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../../libft/libft.h"

typedef struct		s_push_swap
{
	t_tab			*stack_a;
	t_tab			*stack_b;
//	int				*stack_a;
//	int				*stack_b;
	char			*instruction;
	size_t			all;
	size_t			size_a;
	size_t			size_b;
	int				count;
}					t_push_swap;

t_push_swap	*setup_tab(int ac, char **av);
int			is_it_good(t_push_swap *push);
int			print_push_swap(t_push_swap *push);
int			lets_play(t_push_swap *push);


#endif
