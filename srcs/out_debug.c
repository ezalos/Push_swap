/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:54:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:05:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	action_list(void)
{
	int i;

	i = -1;
	ft_putendl("");
	while (++i < (*ft_remember_push())->count)
		ft_printf("%d%s ", i,
		*(char**)ft_tab_dirth((*ft_remember_push())->actions, 0, i)->content);
	ft_putendl("");
}
