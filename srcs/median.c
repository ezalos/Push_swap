/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:28:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 16:09:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	print_it(t_tab *stack)
{
	int		i;
	int		col;

	i = -1;
	col = 0;
	if ((*ft_remember_push())->count > 66)
		col = 15 * 3;
	C_RESET
	while (++i <= 5 + (int)(*ft_remember_push())->size_b)
		ft_tab_print_one_elmnt(ft_tab_dirth(stack, 0, i), 24 + (i * 5), col, *(int*)ft_tab_dirth(stack, 0, i)->content);
}

int		ft_mv(t_push_swap *push, size_t size, int a)
{
	int 	i;
	int 	done;
	int		median;
	int		tip;

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
		// if ((*ft_remember_push())->count > 50)
		if ((*ft_remember_push())->size_b != ft_tabloop_lendir(push->stack_b, 0))
		{
			print_push_swap((*ft_remember_push()));
			ft_printf("%~{?*}Hello\n", i + done);
			print_it(push->stack_b);
			ft_press_any_key();
		}
		// ft_printf("%d<%d && %d<%d\n", i, size, (i - done) * 2, (int)size);
	}
	// if (a)
	// 	ft_printf("%d\tdone:%3d %-3d:size_a\t %d<=%d %d", median, (int)push->size_a, done ,(int)push->size_a - done, stack_a(0));
	// else
	// 	ft_printf("%d\tdone:%3d %-3d:size_b\t %d<=%d %d", median, (int)push->size_b, done ,(int)push->size_a - done, stack_b(0));
	// ft_press_any_key();
	if (a)
		tip = (int)push->size_a;
	else
		tip = (int)push->size_b;
	if (done == tip)
		return (size / 2);
	else if (done < tip - done)
	{
		while (done--)
			if (a)
				rra();
			else
				rrb();
	}
	else
	{
		while (tip - 1 > done++)
			if (a)
				ra();
			else
				rb();
	}
	// print_push_swap(push);
	// ft_putendl("                           ");
	return (size / 2);
}
