/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:27:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/05 20:32:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			print_push_swap(t_push_swap *push)
{
	int		good_a;
	int		now_a;
	int		good_b;
	int		now_b;
	size_t	in;
	t_tab	*tmpa;
	t_tab	*tmpb;
	size_t	dir;

	//CLEAR_SCREEN
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
	//ft_putstr("BONJOUR PBM ?");
	tmpa = (push->stack_a);
	tmpb = (push->stack_b);
	//ft_putstr("BONJOUR PBM !");

	in = 0;
	dir = 2;
	while (in < push->all && (in < push->size_a || in < push->size_b))
	{
		ft_putstr("\n");
		ft_putstr("\t\t\t");
		if (in < push->size_a)
		{
			now_a = *(int*)ft_tab_dirth(push->stack_a, dir, in)->content;
			if (in > 0)
			{
				if (now_a > good_a)
					C_GREEN
				else if (now_a == good_a)
					C_ORANGE
				else
					C_RED
			}
			else
				C_CYAN
			good_a = now_a;
			ft_putnbr(good_a);
		}
		ft_putstr("\t\t");
		if (in < push->size_b)
		{
			now_b = *(int*)ft_tab_dirth(push->stack_b, dir, in)->content;
			if (in > 0)
			{
				if (now_b > good_b)
					C_GREEN
				else if (now_b == good_b)
					C_ORANGE
				else
					C_RED
			}
			else
				C_CYAN
			good_b = now_b;
			ft_putnbr(good_b);
		}
		in++;
	}
	ft_putstr("\n");
	C_RESET
	return (0);
}
