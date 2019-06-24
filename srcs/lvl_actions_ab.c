/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_actions_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:57:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 14:57:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			rr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_double(push, 1))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}

void			rrr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_double(push, 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}
