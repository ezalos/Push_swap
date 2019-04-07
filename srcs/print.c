/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:27:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 21:06:08 by ldevelle         ###   ########.fr       */
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

	return (0);
	CLEAR_SCREEN
	ft_place_cursor(0, 0);
	//CURSOR_RESET
	ft_printf("%~{101;78;163}ACTUAL COUNT: %~{100;100;255}%-15d", push->count);
	ft_printf("%~{220;50;150}Instruction: %~{239;100;100}%7s\n", push->instruction);
	ft_printf("%~{255;255;0}Size total: %~{238;205;163}%-7d", push->all);
	ft_printf("%~{255;255;0}Size A: %~{238;205;163}%-7d", push->size_a);
	ft_printf("%~{255;255;0}Size B: %~{238;205;163}%-7d%~{}\n", push->size_b);
	ft_printf("%50s", " ");
	tmpa = (push->stack_a);
	tmpb = (push->stack_b);
	in = 0;
	dir = 0;
	while (in < push->all || (in < push->size_a || in < push->size_b))
	{
		// if (in)
			ft_putstr("\n");
		ft_putstr("\t\t\t");
		if (in < push->size_a)
		{
			now_a = stack_a(in) - 1;
			if (push->size_a == push->all)
			{
				if (now_a == (int)in)
					C_GREEN
				else if (now_a < (int)in)
					C_YELLOW
				else
					C_RED
			}
			else if (in > 0)
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
			ft_putstr("   ");
		}
		else
		{
			ft_putstr("   ");
		}
		ft_putstr("\t\t");
		if (in < push->size_b)
		{
			now_b = stack_b(in);
			if (in > 0)
			{
				if (now_b < good_b)
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
			ft_putstr("   ");
		}
		else
		{
			ft_putstr("   ");
		}
		in++;
	}
	ft_putstr("\n");
	C_RESET
	return (0);
}
