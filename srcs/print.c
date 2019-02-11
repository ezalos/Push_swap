/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:27:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 20:51:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			print_push_swap(t_push_swap *push)
{
	int		good_a;
	int		good_b;
	size_t	i;

	i = -1;
	CLEAR_SCREEN
	place_cursor(0, 0);
	//CURSOR_RESET
	C_PURPLE
	ft_putstr("ACTUAL COUNT: ");
	C_RESET
	ft_putnbr(push->count);
	C_PURPLE
	ft_putstr("\t\tInstruction: ");
	C_PINK
	ft_putstr(push->instruction);
	C_YELLOW
	ft_putstr("\n");
	ft_putstr("Size total: ");
	C_BROWN
	ft_putnbr(push->all);
	C_YELLOW
	ft_putstr("\tSize A: ");
	C_BROWN
	ft_putnbr(push->size_a);
	C_YELLOW
	ft_putstr("\tSize B: ");
	C_BROWN
	ft_putnbr(push->size_b);
	C_RESET
	ft_putstr("\n");
	while (++i < push->all && (i < push->size_a || i < push->size_b))
	{
		ft_putstr("\n");
		ft_putstr("\t\t\t");
		if (i < push->size_a)
		{
			if (i > 0)
			{
				if (push->stack_a[i] > good_a)
					C_GREEN
				else if (push->stack_a[i] == good_a)
					C_ORANGE
				else
					C_RED
			}
			else
				C_CYAN
			good_a = push->stack_a[i];
			//if ((push->stack_a[i] == 0 && push->size_a == i) || (push->stack_a[i] == 0 && push->stack_a[i + 1] == 0))
			//	C_BLUE
			ft_putnbr(push->stack_a[i]);
		}
		ft_putstr("\t\t");
		if (i < push->size_b)
		{
			if (i > 0)
			{
				if (push->stack_b[i] > good_b)
					C_GREEN
				else if (push->stack_b[i] == good_b)
					C_ORANGE
				else
					C_RED
			}
			else
				C_CYAN
			good_b = push->stack_b[i];
			//if ((push->stack_b[i] == 0 && push->size_b == i) || (push->stack_b[i] == 0 && push->stack_b[i + 1] == 0))
			//	C_BLUE
			ft_putnbr(push->stack_b[i]);
		}
	}
	ft_putstr("\n");
	C_RESET
	return (0);
}
