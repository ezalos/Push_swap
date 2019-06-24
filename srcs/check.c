/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:41:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 14:50:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		is_it_good(t_push_swap *push)
{
	size_t	i;
	int		good;
	t_tab	*tmp;

	i = 0;
	tmp = push->stack_a;
	if (push->size_a != push->all)
		return (0);
	while (++i < push->all)
	{
		good = *(int*)tmp->content;
		tmp = tmp->dir[0];
		if (*(int*)tmp->content <= good)
			return (0);
	}
	return (1);
}
