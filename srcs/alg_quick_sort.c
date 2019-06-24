/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int					master_ba(int size)
{
	int		sent;

	sent = ba(size);
	if (size <= 1)
		return (size);
	master_ab(sent);
	if (PROGRESS)
		ft_progress("AB_BA",
			(*ft_remember_push())->size_a, (*ft_remember_push())->all);
	master_ba(size - sent);
	return (sent);
}

/*
** //MASTER_BA(sent total)
** 		sent = ba(size);
** 		master_ab(sent);
** 		master_ba(size - sent);
**
** //MASTER_AB(sent total)
** 		sent = ab(size);
** 		master_ab(size - sent);
** 		master_ba(sent);
*/

int					master_ab(int size)
{
	int		sent;

	sent = 0;
	if (size > 1 && !order_a(size))
	{
		sent = ab(size);
		master_ab(size + sent);
		master_ba(-sent);
	}
	else if (PROGRESS)
		ft_progress("AB_BA",
			(*ft_remember_push())->size_a, (*ft_remember_push())->all);
	return (0);
}

int					the_choosen_alg(t_push_swap *push)
{
	time_exe(__func__);
	if (PROGRESS)
		ft_progress("AB_BA", 0, push->all);
	master_ab(push->size_a);
	if (PROGRESS)
		ft_progress("AB_BA", push->all,
		push->all);
	return (1);
}
