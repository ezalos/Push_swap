/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:53:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 15:48:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int				execute_double(t_push_swap *push, int mode)
{
	int		r_val;

	r_val = 0;
	if (mode == 0)
	{
		r_val += execute_swap(&push->stack_a);
		r_val += execute_swap(&push->stack_b);
	}
	if (mode == 1)
	{
		r_val += execute_rotation(&push->stack_a, 0);
		r_val += execute_rotation(&push->stack_b, 0);
	}
	if (mode == 2)
	{
		r_val += execute_rotation(&push->stack_a, 2);
		r_val += execute_rotation(&push->stack_b, 2);
	}
	return (r_val);
}

int				extra_push(t_push_swap *push, int a)
{
	if (a)
	{
		if (push->size_a)
			if (execute_push(&push->stack_a, &push->stack_b))
			{
				push->size_a--;
				push->size_b++;
				return (1);
			}
	}
	else
	{
		if (push->size_b)
			if (execute_push(&push->stack_b, &push->stack_a))
			{
				push->size_a++;
				push->size_b--;
				return (1);
			}
	}
	return (0);
}

int				execute_order_66(t_push_swap *push)
{
	if (!ft_strcmp(push->instruction, "sa"))
		return (execute_swap(&push->stack_a));
	else if (!ft_strcmp(push->instruction, "sb"))
		return (execute_swap(&push->stack_b));
	else if (!ft_strcmp(push->instruction, "ss"))
		return (execute_double(push, 0));
	else if (!ft_strcmp(push->instruction, "pb"))
		return (extra_push(push, 1));
	else if (!ft_strcmp(push->instruction, "pa"))
		return (extra_push(push, 0));
	else if (!ft_strcmp(push->instruction, "ra"))
		return (execute_rotation(&push->stack_a, 0));
	else if (!ft_strcmp(push->instruction, "rb"))
		return (execute_rotation(&push->stack_b, 0));
	else if (!ft_strcmp(push->instruction, "rr"))
		return (execute_double(push, 1));
	else if (!ft_strcmp(push->instruction, "rra"))
		return (execute_rotation(&(push->stack_a), 2));
	else if (!ft_strcmp(push->instruction, "rrb"))
		return (execute_rotation(&push->stack_b, 2));
	else if (!ft_strcmp(push->instruction, "rrr"))
		return (execute_double(push, 2));
	return (-1);
}
