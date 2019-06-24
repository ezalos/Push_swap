/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_recognize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:18:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 17:18:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int		ft_recognize_part1(t_tab *action)
{
	if (!ft_strcmp(*(char**)action->dir[0]->content, "sa"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sa"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sb"))
			ft_tab_change_two(action, "ss");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "sb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sb"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sa"))
			ft_tab_change_two(action, "ss");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "pa"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "pb"))
			ft_tab_change_two(action, NULL);
	}
	else
		return (1);
	return (0);
}

static int		ft_recognize_part2(t_tab *action)
{
	if (!ft_strcmp(*(char**)action->dir[0]->content, "pb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "pa"))
			ft_tab_change_two(action, NULL);
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "ra"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rra"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rb"))
			ft_tab_change_two(action, "rr");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "rb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rrb"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "ra"))
			ft_tab_change_two(action, "rr");
	}
	else
		return (1);
	return (0);
}

void			ft_recognize_case(t_tab *action)
{
	if (ft_recognize_part1(action) && ft_recognize_part2(action))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->content, "rra"))
		{
			if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "ra"))
				ft_tab_change_two(action, NULL);
			else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content,
			"rrb"))
				ft_tab_change_two(action, "rrr");
		}
		else if (!ft_strcmp(*(char**)action->dir[0]->content, "rrb"))
		{
			if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rb"))
				ft_tab_change_two(action, NULL);
			else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content,
			"rra"))
				ft_tab_change_two(action, "rrr");
		}
	}
}
