/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:24:31 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 13:35:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int			get_tabint_inint(t_tab *tab, size_t dir, int *array)
{
	t_tab			*ptr;
	int				lin;

	if (tab != NULL)
	{
		ptr = tab;
		lin = 0;
		while (ptr && (ptr != tab || !lin))
		{
			array[lin] = *(int*)ptr->content;
			ptr = ptr->dir[dir];
			lin++;
		}
	}
	return (0);
}

static int			is_it_order(t_push_swap *push)
{
	int				i;
	int				actual;
	int				save;

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

static void			order_one_stack_while(t_push_swap *push, int *solved)
{
	int				now;
	int				next;
	int				save;

	save = push->size_b;
	print_push_swap(push);
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
		save = push->size_b;
}

static int			order_one_stack(t_push_swap *push, int *solved)
{
	while (push->size_a > 1 && !is_it_order(push))
		order_one_stack_while(push, solved);
	while (push->size_b)
	{
		print_push_swap(push);
		pb();
	}
	return (0);
}

int					bubble_it(void)
{
	static int		*solved;
	t_push_swap		*push;

	push = (*ft_remember_push());
	solved = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, solved);
	ft_squick_sort(&solved, 0, push->all - 1);
	order_one_stack(push, solved);
	return (1);
}
