/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_print_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:24:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 14:28:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void				print_header(t_push_swap *push)
{
	ft_printf("%~{101;78;163}ACTUAL COUNT: %~{100;100;255}%-15d", push->count);
	ft_printf("%~{220;50;150}Instruction: %~{239;100;100}%7s%~{}\n",
	push->instruction);
	ft_printf("%~{255;255;0}Size total: %~{238;205;163}%-7d", push->all);
	ft_printf("%~{255;255;0}Size A: %~{238;205;163}%-7d", push->size_a);
	ft_printf("%~{255;255;0}Size B: %~{238;205;163}%-7d%~{}\n", push->size_b);
	ft_printf("%50s", " ");
}

void				special_color(int in, int now)
{
	if (now == (int)in)
		_C_GREEN;
	else if (now < (int)in)
		_C_YELLOW;
	else
		_C_RED;
}

int					print_one_stack(t_push_swap *push, int in, int good, int a)
{
	int		now;

	if (a)
		now = stack_a(in);
	else
		now = stack_b(in);
	if ((push->size_a == push->all && a))
		special_color(in, now);
	else if (in > 0)
	{
		if (((now > good) && (a)) || ((now < good) && (!a)))
			_C_GREEN;
		else if (now == good)
			_C_ORANGE;
		else
			_C_RED;
	}
	else
		_C_CYAN;
	ft_putnbr(now);
	ft_putstr("   ");
	return (now);
}

void				print_stacks(t_push_swap *push)
{
	int		good_a;
	int		good_b;
	size_t	in;

	in = 0;
	while ((in < push->all || (in < push->size_a || in < push->size_b))
	&& (in < IN_SCREEN))
	{
		ft_putstr("\n\t\t\t");
		if (in < push->size_a)
			good_a = print_one_stack(push, in, good_a, 1);
		else
			ft_putstr("   ");
		ft_putstr("\t\t");
		if (in < push->size_b)
			good_b = print_one_stack(push, in, good_b, 0);
		else
			ft_putstr("   ");
		in++;
	}
	ft_putstr("\n");
	_C_RESET;
}

int					print_push_swap(t_push_swap *push)
{
	int		i;

	if (!VISUAL_MODE)
		return (0);
	if (STEP_BY_STEP)
		ft_press_any_key();
	ft_place_cursor(0, 0);
	print_header(push);
	print_stacks(push);
	if (SLOW)
	{
		i = -1;
		while (++i < SLOW)
			ft_wait_pls(0);
	}
	return (0);
}
