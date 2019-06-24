/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_stack_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:25:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:16:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int		ft_get_median(t_tab *stack, size_t size)
{
	int *squick;
	int i;

	squick = ft_memalloc(sizeof(int) * (size));
	i = -1;
	while (++i < (int)size)
		squick[i] = *(int*)ft_tab_dirth(stack, 0, i)->content;
	i = -1;
	ft_squick_sort(&squick, 0, size - 1);
	if (size)
		i = squick[(size - 1) / 2];
	else
		return (-1);
	ft_memdel((void**)&squick);
	return (i);
}

int				median_a(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_a, size));
}

int				median_b(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_b, size));
}
