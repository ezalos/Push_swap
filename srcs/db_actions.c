/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:51:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/09 14:45:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		add_action(char *str)
{
	char	*lec;

	if (!str)
		return (-1);
	time_exe(__func__);
	lec = str;
	if (!(*ft_remember_push())->actions)
		(*ft_remember_push())->actions = ft_tabnew_ptr(&lec, sizeof(char**));
	else
		ft_tabadd_end((*ft_remember_push())->actions,
		ft_tabnew_ptr(&lec, sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	if (VISUAL_MODE == 2)
		print_push_swap((*ft_remember_push()));
	time_exe("__func__");
	return (0);
}
