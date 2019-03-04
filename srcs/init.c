/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:56:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:39:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_push_swap	*setup_tab(int ac, char **av)
{
	t_push_swap		*push;
	int				i;
	int				j;

	push = (t_push_swap*)cnalloc(NULL, sizeof(t_push_swap));
	push->all = ac - 1;
	push->size_a = push->all;
	push->stack_b = ft_tabnew_ptr(cnalloc(NULL, sizeof(t_tab)), sizeof(t_tab*));
	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i + 1][++j])
			if (!ft_isdigit(av[i + 1][j]))
				return (NULL);
		j = ft_atoi(av[i + 1]);
		if (!push->stack_a)
			push->stack_a = ft_tabnew_ptr((int*)cnalloc(&j, sizeof(int)),
			sizeof(int*));
		else
			ft_tabadd_end(push->stack_a, ft_tabnew_ptr((int*)cnalloc(&j,
			sizeof(int)), sizeof(int*)), 0);
	}
	return (push);
}
