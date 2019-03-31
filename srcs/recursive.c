/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:06:08 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:45:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void 		ban(int size)
{
	if (size <= 0)
		return ;
lest_print_recur(size);
	if ((int)(*ft_remember_push())->size_a >= ft_power(2, size) && !order_a(ft_power(2, size)))//8
	{
lest_print_recur2(size);
		if (size == 1)
			sa();
		else
		{
			ab(ft_power(2, size));//8
			ban(size - 1);//4
lest_print_recur3(size - 1, 1);
			ba(ft_power(2, size - 1));//4
		}
	}
	lest_print_recur3(size, 0);
	ba(ft_power(2, size));//8
	ban(size - 1);//4
}

void	think(int size)
{
	CURSOR_LOAD
	ft_printf("%~{255;0;0}%s%~{}(%~{!})%~{}\t%d\n", __func__, size, ft_power(2, size));
	CURSOR_SAVE
	if (size < 0 || (*ft_remember_push())->size_b <= 2)
		return ;
	lest_print_recur3(size, 2);
	ba(ft_power(2, size));
	if (size == 1)
	ba(ft_power(2, size - 1));
	if (size - 1 > 0)
		ban(size - 1);
	// think(size - 1);
	think(size + 1);
}

void 	bob(int size)
{
	if (size <= 0)
		return ;
	ab(ft_power(2, size));//8
	bob(size - 1);//4
	ba(ft_power(2, size - 1));//4
}

void	marley(int size)
{
	// if ((*ft_remember_push())->size_b <= (size_t)ft_power(2, size))
	// {
	// 	marley(size -1);
	// 	return ;
	// }
	if (size < 0 || (*ft_remember_push())->size_b <= 2)
		return ;
	ba(ft_power(2, size));
	if (size - 1 > 0)
		bob(size - 1);
	marley(size + 1);
}

int		algo_tro_bo1(t_push_swap *push)
{
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = -1;
	CURSOR_SAVE
	while (1 < size / ft_power(2, ++i))
	{
		lest_print_recur2(size / (2 * ft_power(2, i)));
		ab(size / ft_power(2, i));
	}
	CURSOR_LOAD
	ft_printf("%s ab has been done %~{!} times\n", __func__, i);
	CURSOR_SAVE
	marley(0);
	if (push->size_b == 2)
		ba(2);
	if (push->size_b == 1)
		ba(1);
	return (1);
}


int		algo_tro_bo2(t_push_swap *push)
{
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = -1;
	CURSOR_SAVE
	while (1 < size / ft_power(2, ++i))
	{
		lest_print_recur2(size / (2 * ft_power(2, i)));
		ab(size / ft_power(2, i));
	}
	CURSOR_LOAD
	ft_printf("%s ab has been done %~{!} times\n", __func__, i);
	CURSOR_SAVE
	think(0);
	if (push->size_b == 2)
		ba(2);
	if (push->size_b == 1)
		ba(1);
	return (1);
}
