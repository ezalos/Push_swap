/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_perfect_ab_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:31:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:25:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void		ab_3_1_1(void)
{
	if ((*ft_remember_push())->size_a == 3)
		ra();
	else
	{
		sa();
		ra();
		sa();
		rra();
	}
}

/*
** ab_3_1_0 takes care of :
** 							2 1 0
** 							2 0 1
** 							1 0 2
*/

static void		ab_3_1_0(int a, int b, int c)
{
	if (b > c && a > c)
	{
		if ((*ft_remember_push())->size_a == 3)
		{
			sa();
			rra();
		}
		else
		{
			sa();
			pa();
			sa();
			ra();
			pb();
			rra();
		}
	}
	else if (a > c && a > c)
		ab_3_1_1();
	else
		sa();
}

static void		ab_3_0_1(void)
{
	if ((*ft_remember_push())->size_a == 3)
		rra();
	else
	{
		pa();
		sa();
		ra();
		pb();
		rra();
	}
}

/*
** ab_3_0_0 takes care of :
** 							0 1 2
** 							0 2 1
** 							1 2 0
*/

static void		ab_3_0_0(int a, int b, int c)
{
	if (b < c && a < c)
		return ;
	else if (c < b && a < c)
	{
		if ((*ft_remember_push())->size_a == 3)
		{
			rra();
			sa();
		}
		else
		{
			pa();
			sa();
			pb();
		}
	}
	else
		ab_3_0_1();
}

void			ab_3(void)
{
	int		a;
	int		b;
	int		c;

	time_exe(__func__);
	a = stack_a(0);
	b = stack_a(1);
	c = stack_a(2);
	if (a < b)
		ab_3_0_0(a, b, c);
	else if (a > b)
		ab_3_1_0(a, b, c);
}
