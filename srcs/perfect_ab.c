/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:54:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 21:05:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	case_1(void)
{

}

void	ab_1(void)
{
	// pa();
}

void	ab_2(void)
{
	if (stack_a(0) >= stack_a(1))
		sa();
	// pa();
}

void	ab_3(void)
{
	int		a;
	int		b;
	int		c;

	a = stack_a(0);
	b = stack_a(1);
	c = stack_a(2);
	if (a < b)
	{
		if (b < c && a < c)		//012
			return ;
		else if (c < b && a < c)//021	put c first
		{
			pa();
			sa();
			pb();
		}
		else					//120	switch b & c
		{
			pa();//20	1
			sa();//02	1
			ra();//2|0	1
			pb();//12|0
			rra();//012
		}
	}
	else if (a > b)
	{
		if (b > c && a > c)		//210	switch a & c
		{
			sa();//120
			pa();//20-1
			sa();//02-1
			ra();//2|0-1
			pb();//12|0
			rra();//012
		}
		else if (a > c && a > c)	//201	put a last
		{
			sa();
			ra();
			sa();
			rra();
		}
		else			//102	switch a & b
			sa();

	}
}

void	ab_4(void)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = stack_a(0);
	b = stack_a(1);
	c = stack_a(2);
	d = stack_a(3);
}

int 	perfect_ab(size_t size)
{
	if (size == 0)
		return (-1);
	else if (size == 1)
		ab_1();
	else if (size == 2)
		ab_2();
	else if (size == 3)
	{
	print_push_swap((*ft_remember_push()));
		ab_3();
	if (!order_a(3))
	{
	ft_press_any_key();
	print_push_swap((*ft_remember_push()));
	ft_press_any_key();
	}
	}
	else if (size == 4)
		ab_4();
	return (-1);
}
