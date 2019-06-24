/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_actions_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:54:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 15:03:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			pa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup("pb");
	if (extra_push(push, 1))
	{
		(*ft_sent_count())--;
		add_action(push->instruction);
	}
	else
	{
		ft_strdel(&push->instruction);
	}
}

void			sa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_swap(&push->stack_a))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}

void			ra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_a, 0))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}

void			rra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&(push->stack_a), 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
}
