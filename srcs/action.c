/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/09 20:10:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_push_swap		**ft_remember_push(void)
{
	static t_push_swap		*push;

	return (&push);
}

void			pa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			pb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			sa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			sb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			ra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			rra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			rb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			rrb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			rr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}

void			rrr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_order_66(push))
		add_action(push->instruction);
	ft_strdel(&push->instruction);
	// push->count++;
}
