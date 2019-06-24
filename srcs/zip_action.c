/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:56:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/09 14:46:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int				ft_tab_change_two(t_tab *act, char *action)
{
	t_tab	*del;
	char	*lec;

	del = ft_tab_cutone(act->dir[0]);
	ft_memdel((void**)&del);
	del = ft_tab_cutone(act->dir[0]);
	ft_memdel((void**)&del);
	(*ft_remember_push())->count--;
	(*ft_remember_push())->count--;
	(*ft_remember_push())->save += 2;
	if (!action)
		return (1);
	(*ft_remember_push())->save--;
	lec = ft_strdup(action);
	ft_tabadd_here(act, ft_tabnew_ptr(&lec, sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	return (0);
}

static void		ft_update_placement(t_tab **action, int *i, int save)
{
	if (save == (*ft_remember_push())->save)
	{
		(*action) = (*action)->dir[0];
		(*i)++;
	}
	else if (*i)
	{
		(*action) = (*action)->dir[2];
		(*i)--;
	}
}

void			ft_print_solution(void)
{
	t_tab	*action;

	action = (*ft_remember_push())->actions;
	while (action)
	{
		ft_printf("%s\n", *(char**)action->content);
		action = action->dir[0];
	}
}

int				traduction(void)
{
	t_tab	*action;
	int		i;
	int		save;

	time_exe(__func__);
	i = 0;
	action = (*ft_remember_push())->actions;
	while (action && action->dir[0] && action->dir[0]->dir[0])
	{
		save = (*ft_remember_push())->save;
		if (PROGRESS)
			ft_progress(__func__, i, (*ft_remember_push())->count);
		ft_recognize_case(action);
		ft_update_placement(&action, &i, save);
	}
	if (PROGRESS)
		ft_progress(__func__, 1, 1);
	print_push_swap((*ft_remember_push()));
	if (PRINT_INSTRUCTIONS)
		ft_print_solution();
	return (1);
}
