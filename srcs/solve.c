/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/25 19:07:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
#include <stdio.h>

int		get_tabint_inint(t_tab *tab, size_t dir, int *array)
{
	t_tab	*ptr;
	int		lin;

	if (tab != NULL)
	{
		ptr = tab;
		lin = 0;
		while (ptr && (ptr != tab || !lin))
		{
			//printf("%p->%d", ptr, *(int*)ptr->content);
			array[lin] = *(int*)ptr->content;
			ptr = ptr->dir[dir];
			lin++;
		}
	}
	return (0);
}

int		sort_mine_increasing(int *array, int size)
{
	int		i;
	int		save;
	int		swap;

	save = 1;
	swap = 0;
	while (save)
	{
		save = 0;
		i = -1;
		while (++i < size)
			if (array[i] < array[i - 1] && ++save)
			{
				ft_swap(&array[i], &array[i - 1], sizeof(int));
				swap++;
			}
	}
	return (swap);
}

int		get_solve_data(t_push_swap *push, int **solved)
{
	int		i;

	solved = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, *solved);
//	solved[0] = push->all;
	i = -1;
	while (++i < (int)push->all)
	{
		ft_putnbr(*solved[i]);
		if (i < (int)push->all - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	ft_putnbr(sort_mine_increasing(*solved, (int)push->all));
	ft_putendl("");
	i = -1;
	while (++i < (int)push->all)
	{
		ft_putnbr(*solved[i]);
		if (i < (int)push->all - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	return (0);
}

int		lets_polve(t_push_swap *push)
{
	if (!(execute_order_66(push)))
		return (-1);
	print_push_swap(push);
	ft_strdel(&push->instruction);
	push->count++;
	return (push->count);
}

int		lets_solve(t_push_swap *push)
{
	static int		*solved;
	t_tab			*tmp;
	int				now;

	if (!solved)
		get_solve_data(push, &solved);
	tmp = push->stack_a;
	while (tmp)
	{
		now = *(int*)tmp->content;
		if (now < solved[push->all / 2])
		{
			push->instruction = ft_strdup("pa");
		}
		else
			push->instruction = ft_strdup("ra");
		lets_polve(push);
		ft_wait_pls(0);
		ft_wait_pls(0);
		ft_wait_pls(0);
	}
	return (0);
}
