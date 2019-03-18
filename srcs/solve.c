/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 20:39:55 by ldevelle         ###   ########.fr       */
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
	int		j;
	int		swap;
	int		save;
	int		count;

	i = -1;
	swap = 0;
	save = -1;
	while (save != swap)
	{
		save = swap;
		i = 0;
		j = 0;
		while (++i < size)
		{
			if (array[j] > array[i])
			{
				ft_swap(&array[i], &array[j], sizeof(int));
				j = i;
				swap++;
			}
		}
	}
	return (swap);
}

int		lets_solve(t_push_swap *push)
{
	int		i;
	int		*solved;

	solved = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, solved);
//	solved[0] = push->all;
	i = -1;
	while (++i < (int)push->all)
	{
		ft_putnbr(solved[i]);
		if (i < (int)push->all - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	ft_putendl("");
	sort_mine_increasing(solved, (int)push->all);
	i = -1;
	while (++i < (int)push->all)
	{
		ft_putnbr(solved[i]);
		if (i < (int)push->all - 1)
			ft_putstr("|");
	}
	return (0);
}
