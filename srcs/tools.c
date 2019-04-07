/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:04:27 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 11:57:52 by ldevelle         ###   ########.fr       */
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
	if (size > (int)push->size_a)
		size = (int)push->size_a;
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
	if (size > (int)push->size_b)
		size = (int)push->size_b;
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

	squick = ft_memalloc(sizeof(int) * (size));
	i = -1;
	while (++i < (int)size)
		squick[i] = *(int*)ft_tab_dirth(stack, 0, i)->content;
	i = -1;
	// CLEAR_SCREEN
	// print_push_swap((*ft_remember_push()));
	// ft_place_cursor(3, 0);
	// while (++i < (int)size)
	// 		ft_printf("%~{}[%d]\t= %-5d\n", i, squick[i]);
	ft_squick_sort(&squick, 0, size - 1);
//	ft_printf("MEDIAN\tsize %d -> [%d]=%d\n", size, (size - 1) / 2, squick[(size - 1) / 2]);
	// i = -1;
	// while (++i < (int)size)
	// 	if (i == (size - 1) / 2)
	// 		ft_printf("%~{150;255;150}[%d]\t= %-5d\n", i, squick[i]);
	// 	else
	// 		ft_printf("%~{255;150;150}[%d]\t= %-5d\n", i, squick[i]);
	if (size)
		i = squick[(size - 1) / 2];
	else
		return (-1);
	ft_memdel((void**)&squick);
	// ft_press_any_key();
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
	int		median;

	// ft_printf("SIZE= %d\n", size);
	if (!size)
		return (0);
	if ((a && (size > push->size_a)) || (!a && (size > push->size_b)))
	{
		// if (a)
		// 	while (size-- / 2)
		// 		pa();
		// else
		// 	while (size-- / 2)
		// 		pb();
		return (0);
	}
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
	if (a)
		median = median_a(size);
	else
		median = median_b(size);
	// ft_printf("SIZE= %d\n", size);
	// C_RESET
	while (i < (int)size && (i - done) * 2 < (int)size)
	{
		if (a)
		{
			if (stack_a(0) <= median)
			{
				// C_GREEN
				// ft_printf("%d\tMEDIAN : %d %d : VALUE\t", i, median, stack_a(0));
				pa();
			}
			else
			{
				// C_RED
				// ft_printf("%d\tMEDIAN : %d %d : VALUE\t", i, median, stack_a(0));
				ra();
				done++;
			}
			// C_RESET
		}
		else
			if (stack_b(0) > median)
				pb();
			else
			{
				rb();
				done++;
			}
		i++;
		// ft_printf("%d<%d && %d<%d\n", i, size, (i - done) * 2, (int)size);
	}
	while (done--)
		if (a)
			rra();
		else
			rrb();
	// print_push_swap(push);
	// ft_putendl("                           ");
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

	if (size == 0)
		return (0);
	if (size == 1)
	{
		pa();
		return (1);
	}
	if (size == 2)
	{
		if (stack_a(0) >= stack_a(1))
			sa();
		pa();
		// if (stack_a(0) >= stack_a(1))
		// 	return (2);
		// else
			return (1);
	}
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
	if (size == 2)
	{
		if (stack_b(0) < stack_b(1))
			sb();
		pb();
		// if (stack_b(0) < stack_b(1))
		// 	return (2);
		// else
			return (1);
	}
	r_v = ft_mv(*ft_remember_push(), size, 0);
	return (r_v);
}

// 		onof = (onof) ? 0 : 1;
