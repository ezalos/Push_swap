/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:42:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:58:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		is_it_order(t_push_swap *push)
{
	int			i;
	int			actual;
	int			save;

	i = -1;
	while (++i < (int)push->size_a)
	{
		actual = stack_a(i);
		if (i && save > actual)
			return (0);
		save = actual;
	}
	return (1);
}

int		order_one_stack(t_push_swap *push, int *solved)
{
	int				now;
	int				next;
	int				save;

	save = push->size_b;
	while (push->size_a > 1 && !is_it_order(push))
	{
		now = stack_a(0);
		next = stack_a(1);
		if (now == solved[push->size_b])
			pa();
		else if (next == solved[push->size_b])
		{
			sa();
			pa();
		}
		else if (now > next)
			sa();
		else
			rra();
		if (save * 2 <= (int)push->size_b)
		{
			if (save)
				ft_printf("%~{!} ", push->size_b);
			save = push->size_b;
		}
	}
	while (push->size_b)
		pb();
	return (0);
}

int		bubble_it(void)
{
	static int		*solved;
	t_push_swap		*push;
	t_tab			*tmp;


	push = (*ft_remember_push());
	print_push_swap(push);
	if (!solved)
		get_solve_data(push, &solved);
	tmp = push->stack_a;
	order_one_stack(push, solved);
	return (1);
}
