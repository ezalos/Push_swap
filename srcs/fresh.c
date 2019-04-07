/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:06:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/06 17:12:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void			lets_see(int mode, int size)
{
	print_push_swap((*ft_remember_push()));
	if (mode == 0)
		ft_printf("%~{?}%s size: (%d)\n", "REPEAT", size);
	else if (mode == 1)
		ft_printf("%~{?}\nSTART BA(%d)\tif(%d)      \n", size, !order_a(size));
	else if (mode == -1)
		ft_printf("%~{?}\n!START      \tif:%d      \n", !order_a(size));
	else if (mode == 2)
		ft_printf("%~{?}\n\n\tAB(%d)\n", size);
	else if (mode == -2)
		ft_printf("%~{?}BANAB OF (%d)\n", size);
	if (mode >= 0)
		ft_press_any_key();

}

/*
** static void 		banab(int size, int start)
** {
** 	if (size < 0)
** 		return ;
** 	if (start)
** 		ba(ft_power(2, size + 1));
** 	if (!order_a(ft_power(2, size)))
** 	{
** 		ab(ft_power(2, size));
** 		banab(size - 1, 0);
** 	}
** 	banab(size - 1, 1);
** }
*/

void 		banaba(int size, int start);

static void 		last_one(void)
{
	while ((*ft_remember_push())->size_b)
		banaba((*ft_remember_push())->size_b, 1);
}

void 		banaba(int size, int start)
{
	int		opt;

	opt = 0;
	if (size <= 0)
		return ;
	if (start)
	{
		if (size > (int)(*ft_remember_push())->size_b)
		{
			last_one();
			return ;
		}
		else
			ba(size);
	}
	if (size % 2)
		size++;
	size /= 2;
	if (!order_a(size))
	{
		ab(size);
		opt = 1;
		banaba(size, 0);
	}
	if (opt)
		banaba(size, 1);
}

static int	repeata(void)
{
	t_push_swap		*push;
	int				size;
	// int			i;

	push = (*ft_remember_push());
	size = push->size_a;
	if (!order_a(push->size_a))
	{
		ab(size);
		repeata();
		banaba(size, 1);
	}
	return (0);
}

int		fresh_start(t_push_swap *push)
{
	// t_list	*
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = 0;
	repeata();
	return (1);
}
