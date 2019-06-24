/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_perfect_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:40:11 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/09 14:46:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void	ba_3_1(int a, int b, int c)
{
	if (b < c && a < c)
	{
		rb();
		sb();
		pb();
		pb();
		rrb();
		pb();
	}
	else if (a < c && a < c)
	{
		sb();
		pb();
		sb();
		pb();
		pb();
	}
	else
	{
		sb();
		pb();
		pb();
		pb();
	}
}

static void	ba_3_0(int a, int b, int c)
{
	if (b > c && a > c)
	{
		pb();
		pb();
		pb();
	}
	else if (c > b && a > c)
	{
		pb();
		sb();
		pb();
		pb();
	}
	else
	{
		rb();
		sb();
		pb();
		rrb();
		pb();
		pb();
	}
}

static void	ba_3(void)
{
	int		a;
	int		b;
	int		c;

	time_exe(__func__);
	a = stack_b(0);
	b = stack_b(1);
	c = stack_b(2);
	if (a > b)
		ba_3_0(a, b, c);
	else if (a < b)
		ba_3_1(a, b, c);
}

int			ba(size_t size)
{
	(*ft_sent_count()) = 0;
	if (size == 0)
		return (0);
	else if (size == 1)
		pb();
	else if (size == 2)
	{
		if (stack_b(0) < stack_b(1))
			sb();
		pb();
	}
	else if (size == 3)
		ba_3();
	else if (size <= INSERT_SWITCH)
		ft_insert_push_ba(size);
	else
		ft_mv(*ft_remember_push(), size, 0);
	if (VISUAL_MODE == 1)
		print_push_swap((*ft_remember_push()));
	return ((*ft_sent_count()));
}
