/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_smart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:03:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:46:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void		ba1(void)
{
char *line;
ft_putendl(__func__);
get_next_line(0, &line);
	pb();
	// ba(ft_power(2, 0));
}

void		ba2(void)
{
char *line;
ft_putendl(__func__);
get_next_line(0, &line);
	if (stack_b(0) < stack_b(1))
		sb();
	pb();
	//ba(ft_power(2, 1));
	ba1();
}

void		ba3(void)
{
char *line;
ft_putendl(__func__);
get_next_line(0, &line);
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
char *line;
ft_putendl(__func__);
get_next_line(0, &line);
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
	char *line;
	ft_putendl(__func__);
	get_next_line(0, &line);
	ba4();
}


void	not_smart(void)
{
	int		size;
	int i;

	size = (*ft_remember_push())->size_a;
	i = -1;
	while (1 < size / ft_power(2, ++i))
		ab(size / ft_power(2, i));
	ba1();
	ba2();
	ba3();
	ba4();
	ba5();
}

/*
** 	//for 1
** 	ba(ft_power(2, 0));
**
** 	//for 2
** 		ba(ft_power(2, 1));
** 	ba(ft_power(2, 0));
**
** 	//for 4
** 			ba(ft_power(2, 2));
** 		ab(ft_power(2, 1));
** 	ba(ft_power(2, 0));
** 		ba(ft_power(2, 1));
** 	ba(ft_power(2, 0));
**
** 	//for end
** 	// ba(ft_power(2, 0));
**
** 	// ba(push->size_b);
*/
