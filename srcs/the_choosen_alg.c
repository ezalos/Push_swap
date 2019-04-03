/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_choosen_alg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/03 21:19:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void 		banab(int size, int start)
{
	if (size < 0)
		return ;
	if (start)
		ba(ft_power(2, size + 1));
	if (!order_a(ft_power(2, size)))
	{
		ab(ft_power(2, size));
		banab(size - 1, 0);
	}
	banab(size - 1, 1);
}

static int	repeat(int size)
{
	if (!(*ft_remember_push())->size_b)
		return (size);
	banab(size, 1);
	return (repeat(size + 1));
}

int		the_choosen_alg(t_push_swap *push)
{
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = 0;
	while (1 < push->size_a && !order_a(push->size_a) && ++i)
		ab(push->size_a);
	repeat(1);
	// ft_printf("\nab : %d\tba : %d\n", repeat(1), i);
	return (1);
}
