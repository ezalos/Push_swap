/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_smart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:03:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/03 20:15:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void		ba1(void)
{
// char *line;
// ft_putendl(__func__);
// get_next_line(0, &line);
	pb();
	// ba(ft_power(2, 0));
}

void		ba2(void)
{
// char *line;
// ft_putendl(__func__);
// get_next_line(0, &line);
	if (stack_b(0) < stack_b(1))
		sb();
	pb();
	ba1();
}

void		ba3(void)
{
// char *line;
// ft_putendl(__func__);
// get_next_line(0, &line);
	int		i;

	i = 2;
	ba(ft_power(2, i--));//4
	if (!order_a(ft_power(2, i)))//2
	{
		ab(ft_power(2, i--));//2
		ba1();//1
	}
	ba2();
}

void		ba4(void)
{
// char *line;
// ft_putendl(__func__);
// get_next_line(0, &line);
	int		i;

	i = 3;
	ba(ft_power(2, i--));//8
	if (!order_a(ft_power(2, i)))//4
	{
		ab(ft_power(2, i--));//4//SAME AS BA4 ONLY HERE BA INSTEAD OF AB
		if (!order_a(ft_power(2, i)))//2
		{
			ab(ft_power(2, i--));//2
			ba1();//1
		}
		ba2();
	}
	ba3();
}

void		ba5(void)
{
	int		i;

	i = 4;
	ba(ft_power(2, i--));//16
	if (!order_a(ft_power(2, i)))//8
	{
		ab(ft_power(2, i--));//8
		if (!order_a(ft_power(2, i)))//4
		{
			ab(ft_power(2, i--));//4
			if (!order_a(ft_power(2, i)))//2
			{
				ab(ft_power(2, i--));//2
				ba1();//1
			}
			ba2();
		}
		ba3();
	}
	// char *line;
	// ft_putendl(__func__);
	// get_next_line(0, &line);
	ba4();
}

/*
** void		ba1(void)
** {
** 	ba(1);
** }
**
** void		ba2(void)
** {
** 	ba(2);
** 	ba(1);
** }
**
** void		ba3(void)
** {
** 	ba(4);
** 	if (!order_a(2))//2
** 	{
** 		ab(2);//2
** 		ba(1);
** 	}
** 	ba2();
** }
**
** void		ba4(void)
** {
** 	ba(8);
** 	if (!order_a(4))
** 	{
** 		ab(4);
** 		if (!order_a(2))
** 		{
** 			ab(2);
** 			ba(1);
** 		}
** 		ba2();
** 	}
** 	ba3();
** }
**
** void		ba5(void)
** {
** 	ba(16);
** 	if (!order_a(8))
** 	{
** 		ab(8);
** 		if (!order_a(4))
** 		{
** 			ab(4);
** 			if (!order_a(2))
** 			{
** 				ab(2);
** 				ba(1);
** 			}
** 			ba2();
** 		}
** 		ba3();
** 	}
** 	ba4();
** }
*/

void	not_smart(void)
{
	int		size;
	int i;

	size = (*ft_remember_push())->size_a;
	i = -1;
	print_push_swap(*ft_remember_push());
	while (1 < size / ft_power(2, ++i))
	{
		// ft_press_any_key();
		ab((*ft_remember_push())->size_a);
	}
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
	ba1();
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
	ba2();
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
	ba3();
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
	ba4();
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
	ba5();
	print_push_swap(*ft_remember_push());
	// ft_press_any_key();
}

/*
** 	//for 1
** 	ba(1);
**
** 	//for 2
** 		ba(2);
** 	ba(1);
**
** 	//for 4
** 			ba(4);
** 		ab(2);
** 	ba(1);
** 		ba(2);
** 	ba(1);
**
** 	//for end
** 	// ba(1);
**
** 	// ba(push->size_b);
*/
