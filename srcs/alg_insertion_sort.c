/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_insertion_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:10:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 15:25:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int					ft_find_biggest_b(int start, int size)
{
	int				i;
	int				winner;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = start;
	winner = start;
	while (++i < size + start)
		if (stack_b(i) > stack_b(winner))
			winner = i;
	return (winner);
}

int					ft_find_second_biggest_b(int start, int size)
{
	int				i;
	int				biggest;
	int				second;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = start;
	biggest = ft_find_biggest_b(start, size);
	second = start;
	while (++i < size + start)
		if (stack_b(i) > stack_b(second) && stack_b(i) < stack_b(biggest))
			second = i;
	return (second);
}

int					go_to_b_th(int access, int on)
{
	int				moved;
	int				neg;

	moved = 0;
	neg = 1;
	if (access < 0 && (access = -access))
		neg = -1;
	if (!(*ft_remember_push())->size_b
	&& !(access = access % (int)(*ft_remember_push())->size_b))
		return (0);
	if (access <= (int)(*ft_remember_push())->size_b - access)
		while (neg * moved < access)
		{
			if (on)
				neg == 1 ? rb() : rrb();
			moved += neg;
		}
	else
		while (neg * -moved < (int)(*ft_remember_push())->size_b - access)
		{
			if (on)
				neg == -1 ? rb() : rrb();
			moved += -neg;
		}
	return (moved);
}

int					ft_auto_stoppeur(int *size, int *moved, int *focus)
{
	int				temp;
	int				option;

	option = ft_find_second_biggest_b(-*moved, *size);
	option = go_to_b_th(option, 0);
	if ((0 <= option && option < *focus)
	|| (0 >= option && option > *focus))
	{
		*moved += (temp = go_to_b_th(option, 1));
		*focus -= temp;
		pb();
		if (*focus > 0)
			(*focus)--;
		(*size)--;
		option = 1;
		print_push_swap((*ft_remember_push()));
	}
	else
		option = 0;
	return (option);
}

int					ft_insert_push_ba(int size)
{
	int				focus;
	int				option;
	int				moved;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	moved = 0;
	while (size)
	{
		focus = ft_find_biggest_b(-moved, size);
		focus = go_to_b_th(focus, 0);
		if (HITCHHIKER)
			option = ft_auto_stoppeur(&size, &moved, &focus);
		moved += go_to_b_th(focus, 1);
		pb();
		if (HITCHHIKER && option)
			sa();
		print_push_swap((*ft_remember_push()));
		size--;
		if (PROGRESS)
			ft_progress("AB_BA", (*ft_remember_push())->size_a,
			(*ft_remember_push())->all);
	}
	return (1);
}
