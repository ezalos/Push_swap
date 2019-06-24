/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_actions_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:57:08 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 15:03:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			pb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup("pa");
	if (extra_push(push, 0))
	{
		(*ft_sent_count())++;
		add_action(push->instruction);
	}
	else
	{
		ft_strdel(&push->instruction);
	}
}

void			sb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_swap(&push->stack_b))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}

void			rb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_b, 0))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}

void			rrb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_b, 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}
