/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:54:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/08 17:30:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	dg(void)
{
	ft_press_any_key();
	print_push_swap((*ft_remember_push()));
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
		else					//120	switch b & c
		{
			if ((*ft_remember_push())->size_a == 3)
			{
				rra();
			}
			else
			{
				pa();//20	1
				sa();//02	1
				ra();//2|0	1
				pb();//12|0
				rra();//012
			}
		}
	}
	else if (a > b)
	{
		if (b > c && a > c)		//210	switch a & c
		{
			if ((*ft_remember_push())->size_a == 3)
			{
				sa();
				rra();
			}
			else
			{
				sa();//120
				pa();//20-1
				sa();//02-1
				ra();//2|0-1
				pb();//12|0
				rra();//012
			}
		}
		else if (a > c && a > c)	//201	put a last
		{
			if ((*ft_remember_push())->size_a == 3)
			{
				ra();
			}
			else
			{
				sa();
				ra();
				sa();
				rra();
			}
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
	// show_it();
	if		(a < b && b < c && c < d)	//0123
	{
		// ft_printf("0123\n");
		return ;
	}
	else if (a < b && b < d && d < c)	//0132
	{
		// ft_printf("0132\n");
		pa();
		ab_3();
		pb();
	}
	else if (a < c && c < b && b < d)	//0213
	{
		// ft_printf("0213\n");
		pa();
		ab_3();
		pb();
	}
	else if (a < d && d < b && b < c)	//0231
	{
		// ft_printf("0231\n");
		pa();
		ab_3();
		pb();
	}
	else if (a < c && c < d && d < b)	//0312
	{
		// ft_printf("0312\n");
		pa();
		ab_3();
		pb();
	}
	else if (a < d && d < c && c < b)	//0321
	{
		// ft_printf("\n");
		pa();
		ab_3();
		pb();
	}
	else if (b < a && a < c && c < d)	//1023
	{
		// ft_printf("1023\n");
		ab_3();
	}
	else if (b < a && a < d && d < c)	//1032
	{
		// ft_printf("1032\n");
		///*		//6 moves
		sa();
		pa();
		ab_3();
		pb();
		//*/
	}
	else if (c < a && a < b && b < d)	//1203
	{
		// ft_printf("1203\n");
		ab_3();
	}
	else if (d < a && a < b && b < c)	//1230
	{
		// ft_printf("1230\n");
		ra();
		ra();
		ra();//0|123
		pa();//|123	0
		rra();
		rra();
		rra();//123	0
		pb();//0123
	}
	else if (c < a && a < d && d < b)	//1302
	{
		// ft_printf("1302\n");
		pa();
		sa();
		ra();
		sa();
		pb();
		rra();
	}
	else if (d < a && a < c && c < b)	//1320
	{
		// ft_printf("1320\n");
		ra();
		sa();
		ra();
		ra();
		pa();
		rra();
		rra();
		rra();
		pb();
	}
	else if (c < b && b < a && a < d)	//2103
	{
		// ft_printf("2103\n");
		ab_3();
	}
	else if (d < b && b < a && a < c)	//2130
	{
		// ft_printf("2130\n");
		sa();	//1230
		ra();	//230|1
		ra();	//30|12
		ra();	//0|123
		pa();	//|123	0
		rra();	//3|12	0
		rra();	//23|1	0
		rra();	//123|	0
		pb();	//0123
	}
	else if (b < c && c < a && a < d)	//2013
	{
		// ft_printf("2013\n");
		ab_3();
	}
	else if (b < d && d < a && a < c)	//2031
	{
		// ft_printf("2031\n");
		sa();//0231
		pa();
		ab_3();
		pb();
	}
	else if (d < c && c < a && a < b)	//2310
	{
		// ft_printf("2310\n");
		ra();
		ra();
		pa();
		pa();
		rra();
		rra();
		sb();
		pb();
		pb();
	}
	else if (c < d && d < a && a < b)	//2301
	{
		// ft_printf("2301\n");
		pa();
		pa();
		ra();
		ra();
		// sb();
		pb();
		pb();
		rra();
		rra();
	}
	else if (d < b && b < c && c < a)	//3120
	{
		// ft_printf("3120\n");
		pa();//120	3
		ra();//20|1
		ra();//0|12	3
		pa();//|12	03
		sb();//|12	30
		pb();//3|12	0
		rra();
		rra();
		pb();
	}
	else if (c < b && b < d && d < a)	//3102
	{
		// ft_printf("3102\n");
		pa();//102	3
		sa();//012	3
		ra();//12|0	3
		ra();//2|01	3
		ra();//|012	3
		pb();//3|012
		rra();
		rra();
		rra();//0123
	}
	else if (d < c && c < b && b < a)	//3210
	{
		// ft_printf("3210\n");
		pa();
		pa();//10 23
		sb();
		sa();//01 32
		ra();
		ra();
		pb();
		pb();
		rra();
		rra();
	}
	else if (c < d && d < b && b < a)	//3201
	{
		// ft_printf("3201\n");
		sa();
		ra();
		ra();
		pa();
		pa();
		rra();
		rra();
		pb();
		pb();
	}
	else if (b < c && c < d && d < a)	//3012
	{
		// ft_printf("3012\n");
		pa();//012 3
		ra();
		ra();
		ra();//|012 3
		pb();
		rra();
		rra();
		rra();
	}
	else if (b < d && d < c && c < a)	//3021
	{
		// ft_printf("3021\n");
		pa();
		ra();
		sa();
		ra();
		ra();
		pb();
		rra();
		rra();
		rra();
	}
	else
	{
		ft_printf("CAN'T CATEGORIZE: %d %d %d %d\n", a, b, c, d);
		ft_press_any_key();
	}
}

int 	perfect_ab(size_t size)
{
	print_push_swap((*ft_remember_push()));
	if (size == 0)
		return (-1);
	else if (size == 1)
		ab_1();
	else if (size == 2)
		ab_2();
	else if (size == 3)
		ab_3();
	else if (size == 4)
		ab_4();
	if (!order_a(size))
	{
		ft_press_any_key();
		print_push_swap((*ft_remember_push()));
		ft_press_any_key();
	}
	return (-1);
}
