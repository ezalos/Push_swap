/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:56:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/09 20:40:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		add_action(char *str)
{
	t_tab	*actions;
	t_tab	*new;
	char	*lec;
	// char	**leco;

	if (!str)
		return (-1);
	actions = (*ft_remember_push())->actions;
	lec = ft_strdup(str);
	new = ft_tabnew_ptr(&lec, sizeof(char**));
	// new = ft_tabnew_ptr((char*)ft_strdup(str), sizeof(char*));
	if (!(*ft_remember_push())->actions)
		(*ft_remember_push())->actions = ft_tabnew_ptr((char**)cnalloc(&lec, sizeof(char*)), sizeof(char**));
	else
		ft_tabadd_end((*ft_remember_push())->actions, ft_tabnew_ptr((char**)cnalloc(&lec, sizeof(char*)), sizeof(char**)), 0);
	// lec = *(char**)ft_tab_dirth((*ft_remember_push())->actions, 0, 0)->content;
	// ft_printf("%s ", lec);
	(*ft_remember_push())->count++;
	return (0);
}
