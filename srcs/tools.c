/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:04:27 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:39:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		order_a(int size)
{
	int			i;
	int			actual;
	int			save;
	t_push_swap	*push;

	i = -1;
	push = *ft_remember_push();
	while (++i < size)
	{
		actual = *(int*)ft_tab_dirth(push->stack_a, 0, i)->content;
		if (i && save > actual)
			return (0);
		save = actual;
	}
	return (1);
}

int		order_b(int size)
{
	int			i;
	int			actual;
	int			save;
	t_push_swap	*push;

	i = -1;
	push = *ft_remember_push();
	while (++i < size)
	{
		actual = *(int*)ft_tab_dirth(push->stack_b, 0, i)->content;
		if (i && save > actual)
			return (0);
		save = actual;
	}
	return (1);
}

int		ft_get_median(t_tab *stack, size_t size)
{
	int *squick;
	int i;

	squick = ft_memalloc(sizeof(int) * (size + 1));
	i = -1;
	while (++i < (int)size)
		squick[i] = *(int*)ft_tab_dirth(stack, 0, i)->content;
	ft_squick_sort(&squick, 0, size);
	i = squick[size / 2];
	ft_memdel((void**)&squick);
	return (i);
}

int		median_a(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_a, size));
}

int		median_b(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_b, size));
}

int		ft_mv(t_push_swap *push, size_t size, int a)
{
	int 	i;
	int 	done;

	if (!size)
		return (0);
	if ((a && (size > push->size_a)) || (!a && (size > push->size_b)))
		return (0);
	if (size == 1)
	{
		if (a)
			pa();
		else
			pb();
		return (1);
	}
	i = 0;
	done = 0;
	while (i < (int)size && (i - done) < (int)size / 2)
	{
		if (a)
		{
			if (stack_a(0) <= median_a(size))
				pa();
			else
			{
				ra();
				done++;
			}
		}
		else
			if (stack_b(0) > median_b(size))
				pb();
			else
			{
				rb();
				done++;
			}
		i++;
	}
	while (done--)
		if (a)
			rra();
		else
			rrb();
	print_push_swap(push);
	return (size / 2);
}

int			stack_a(int i)
{
	t_tab		*stack;

	stack = (*ft_remember_push())->stack_a;
	return (*(int*)ft_tab_dirth(stack, 0, i)->content);
}

int			stack_b(int i)
{
	t_tab		*stack;

	stack = (*ft_remember_push())->stack_b;
	return (*(int*)ft_tab_dirth(stack, 0, i)->content);
}

int		ab(size_t size)
{
	int		r_v;

	r_v = ft_mv(*ft_remember_push(), size, 1);
	return (r_v);
}

int		ba(size_t size)
{
	int		r_v;

	if (size == 0)
		return (0);
	if (size == 1)
	{
		pb();
		return (1);
	}
	if (size ==2)
	{
		if (stack_b(0) < stack_b(1))
			sb();
		pb();
		if (stack_b(0) < stack_b(1))
			return (2);
		else
			return (1);
	}
	r_v = ft_mv(*ft_remember_push(), size, 0);
	return (r_v);
}

// char *line;
// get_next_line(0, &line);
// if (size > 2)
// {
// 	sav = size / 2;
// 	onof = 1;
// 	while (sav)
// 	{
// 		r_v += ft_mv(*ft_remember_push(), sav, onof);
// 		sav /= 2;
// 		onof = (onof) ? 0 : 1;
// 	}
// }
