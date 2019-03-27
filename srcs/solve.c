/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/27 22:03:09 by ldevelle         ###   ########.fr       */
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
	print_int_tab(*solved, (int)push->all);
	ft_putnbr(sort_mine_increasing(*solved, (int)push->all));
	ft_putendl("");
	ft_putendl("\nBubble sort :");
	print_int_tab(*solved, (int)push->all);
	quick = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, quick);
	ft_quick_sort(&quick, 0, push->all - 1, &count);
	ft_putendl("\nQuick sort :");
	print_int_tab(quick, (int)push->all);
	ft_putnbr(count);
	squick = ft_memalloc(sizeof(int) * (push->all + 1));
	get_tabint_inint(push->stack_a, 0, squick);
	ft_putendl("");
	ft_squick_sort(&squick, 0, push->all - 1);
	ft_putendl("\nSQuick sort :");
	print_int_tab(squick, (int)push->all);
	get_next_line(0, &line);
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

int		split_pusha(t_push_swap *push, int *solved)
{
	int				now;

	while (((push->size_b <= push->size_a - 2) && push->all % 2)
	|| ((push->size_b <= push->size_a - 1 ) && !(push->all % 2)))
	{
		now = *(int*)push->stack_a->content;
		ft_printf("now: %d\t%d :ref\t", now, solved[push->all / 2]);
		if (now < solved[push->all / 2])
		{
			push->instruction = ft_strdup("pa");
		}
		else
			push->instruction = ft_strdup("ra");
		// scanf("%d\n", &now);
		lets_polve(push);
	}
	return (1);
}

int		is_it_order(t_push_swap *push)
{
	int			i;
	int			actual;
	int			save;

	i = -1;
	while (++i < (int)push->size_a)
	{
		actual = *(int*)ft_tab_dirth(push->stack_a, 0, i)->content;
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

	while (push->size_a > 1 && !is_it_order(push))
	{
		now = *(int*)push->stack_a->content;
		next = *(int*)push->stack_a->dir[0]->content;
		if (now == solved[push->size_b])
			push->instruction = ft_strdup("pa");
		else if (next == solved[push->size_b])
		{
			push->instruction = ft_strdup("sa");
			lets_polve(push);
			push->instruction = ft_strdup("pa");
		}
		else if (now > next)
			push->instruction = ft_strdup("sa");
		else
			push->instruction = ft_strdup("rra");
		lets_polve(push);
	}
	while (push->size_b)
	{
		push->instruction = ft_strdup("pb");
		lets_polve(push);
	}
	return (0);
}

int		lets_solve(t_push_swap *push)
{
	static int		*solved;
	t_tab			*tmp;

	if (!solved)
		get_solve_data(push, &solved);
	tmp = push->stack_a;
	order_one_stack(push, solved);
	// split_pusha(push, solved);
	return (0);
}
