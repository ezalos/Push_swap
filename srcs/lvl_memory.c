/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:53:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:07:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_rotation(t_tab **stack, size_t dir)
{
	t_tab	*tmp;

	if (!stack || !*stack)
		return (0);
	tmp = ft_tab_dirth(*stack, dir, 1);
	*stack = tmp;
	return (1);
}

int		execute_swap(t_tab **stack)
{
	t_tab	*tmp;
	size_t	len;

	len = ft_tabloop_lendir(*stack, 0);
	if (len < 1)
		return (0);
	else if (len == 1)
	{
		execute_rotation(stack, 0);
		return (1);
	}
	tmp = ft_tab_cutone((*stack)->dir[0]);
	ft_tabadd(stack, tmp, 0, 0);
	return (1);
}

int		execute_push(t_tab **stack_a, t_tab **stack_b)
{
	t_tab	*tmp;

	if (!stack_a || !*stack_a)
		return (0);
	if (ft_tabloop_lendir(*stack_a, 0) <= 1)
	{
		ft_tabadd_start(stack_b, *stack_a, 0);
		*stack_a = NULL;
	}
	else
	{
		execute_rotation(stack_a, 2);
		tmp = ft_tab_cutone((*stack_a)->dir[0]);
		ft_tabadd_start(stack_b, tmp, 0);
		ft_tabloop_it(*stack_b, 0);
		execute_rotation(stack_a, 0);
	}
	return (1);
}
