/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:43:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 14:46:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(int ac, char **av)
{
	t_push_swap		*push;

	if (VISUAL_CHECKER)
		_CLEAR_SCREEN;
	if (ac <= 1)
		return (0);
	if (!(push = setup_tab(ac - 1, av)))
		ft_burn_garbage(NULL);
	if (exe_actions(push) == -1)
		ft_burn_garbage(NULL);
	if (VISUAL_CHECKER)
		visual_checker(push);
	if (is_it_good(push))
	{
		ft_clean_garbage();
		return (ft_putstr_r0_fd("OK\n", 1));
	}
	ft_clean_garbage();
	return (ft_putstr_r0_fd("KO\n", 1));
}
