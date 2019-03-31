/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:25:19 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:53:26 by ldevelle         ###   ########.fr       */
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

int		print_int_tab(int *solved, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i)
		{
			if ((solved)[i - 1] < (solved)[i])
				C_GREEN
			else
				C_RED
		}
		ft_putnbr((solved)[i]);
		C_RESET
		if (i < size - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	return (0);
}

int		print_dos_tab(int *solved, int *unsolved, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i)
		{
			if ((solved)[i - 1] < (solved)[i])
				C_GREEN
			else
				C_RED
		}
		ft_putnbr((solved)[i]);
		if (solved[i] < 10)
			ft_putstr(" ");
		C_RESET
		if (i < size - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	i = -1;
	while (++i < size)
	{
		if (i)
		{
			if ((unsolved)[i] == (solved)[i])
				C_CYAN
			else if ((unsolved)[i - 1] < (unsolved)[i])
				C_GREEN
			else
				C_RED
		}
		ft_putnbr((unsolved)[i]);
		if (unsolved[i] < 10)
			ft_putstr(" ");
		C_RESET
		if (i < size - 1)
			ft_putstr("|");
	}
	ft_putendl("");
	return (0);
}

int		*my_size(void)
{
	static int	mem;

	return (&mem);
}

void	ft_print_qs(int **array, int pivot, int look_left, int look_right)
{
	int		size;
	int		i;

	size = *my_size();
	i = -1;
	while (++i <= size)
	{
		if ((*array)[i] == pivot)
			C_CYAN
		else if (i == look_left)
			C_GREEN
		else if (i == look_right)
			C_RED
		else if (look_left < i && i < look_right)
			C_YELLOW
		ft_putnbr((*array)[i]);
		C_RESET
		if (i < size)
			ft_putstr("|");
	}
	ft_putendl("");
}

int		get_solve_data(t_push_swap *push, int **solved)
{
	char *line;
	int *quick;
	int *squick;
	int	count;

	*my_size() = push->all - 1;
	*solved = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, *solved);
	// print_int_tab(*solved, (int)push->all);
	ft_squick_sort(solved, 0, push->all - 1);
	// sort_mine_increasing(*solved, (int)push->all);
	return (0);
	ft_putnbr(sort_mine_increasing(*solved, (int)push->all));
	ft_putendl("");
	ft_putendl("\nBubble sort :");
	// print_int_tab(*solved, (int)push->all);
	quick = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, quick);
	ft_quick_sort(&quick, 0, push->all - 1, &count);
	ft_putendl("\nQuick sort :");
	// print_int_tab(quick, (int)push->all);
	ft_putnbr(count);
	squick = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, squick);
	ft_putendl("");
	ft_squick_sort(&squick, 0, push->all - 1);
	ft_putendl("\nSQuick sort :");
	// print_int_tab(squick, (int)push->all);
	// ft_putendl("");
	// ft_putendl("");
	// get_tabint_inint(push->stack_a, 0, *solved);
	// print_dos_tab(squick, *solved, push->all - 1);
	get_next_line(0, &line);
	return (0);
}
