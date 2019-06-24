/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 15:43:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		end(t_push_swap *push, int ac, char **av)
{
	if (is_it_good(push))
	{
		if (FILE_OUTPUT)
			ft_save_file_exit_ok(push, ac, av);
		ft_clean_garbage();
		if (CHECKER)
			return (ft_putstr_r0_fd("OK\n", 1));
	}
	else if (FILE_OUTPUT)
		ft_save_file_exit_ko(ac, av);
	ft_clean_garbage();
	if (CHECKER)
		return (ft_putstr_r0_fd("KO\n", 1));
	return (0);
}

int		main(int ac, char **av)
{
	t_push_swap		*push;

	if (VISUAL_MODE)
		_CLEAR_SCREEN;
	if (ac <= 1)
		return (0);
	if (!(push = setup_tab(ac - 1, av)))
		ft_burn_garbage(NULL);
	if (FILE_OUTPUT)
		ft_save_arguments("./tests/last", ac, av);
	lets_solve(push);
	traduction();
	if (COUNT)
		ft_printf("%d\n", push->count);
	return (end(push, ac, av));
}
