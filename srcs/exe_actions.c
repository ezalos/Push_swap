/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/08 14:34:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			visual_checker(t_push_swap *push)
{
	int		i;

	ft_place_cursor(0, 0);
	print_header(push);
	print_stacks(push);
	if (SLOW)
	{
		i = -1;
		while (++i < SLOW)
			ft_wait_pls(0);
	}
}

int				get_actions(t_push_swap *push)
{
	char		act[4];
	int			cursor;
	int			r_v;

	cursor = 0;
	while ((r_v = read(0, act + cursor, 1)) > 0)
	{
		if (act[cursor] == '\n')
		{
			push->instruction = ft_strnew(cursor);
			ft_memmove(push->instruction, act, cursor);
			return (0);
		}
		else if (cursor > 3)
			return (-1);
		cursor++;
	}
	if (r_v == -1 || (act[2] != '\n' && act[3] != '\n')
	|| (act[2] == '\n' && act[3] == '\n'))
		return (-1);
	push->instruction = ft_strnew(cursor);
	ft_memmove(push->instruction, act, cursor);
	return (0);
}

int				exe_actions(t_push_swap *push)
{
	int			r_v;

	print_push_swap(push);
	if (-1 == get_actions(push))
		return (0);
	while (push->instruction[0] != '\0')
	{
		if (-1 == (r_v = execute_order_66(push)))
			return (-1);
		if (r_v)
			push->count++;
		if (VISUAL_CHECKER == 1
		|| (VISUAL_CHECKER == 2 && (JUMP && !(push->count % JUMP))))
			visual_checker(push);
		else if (VISUAL_MODE)
			print_push_swap(push);
		ft_strdel(&push->instruction);
		if (-1 == get_actions(push))
			return (0);
	}
	ft_strdel(&push->instruction);
	return (push->count);
}
