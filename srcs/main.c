/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:35:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(int ac, char **av)
{
	t_push_swap		*push;
	size_t			size;

	if (ac <= 1)
		return (ft_putstr_r0("Error\n"));
	size = ac - 1;
	if (!(push = setup_tab(size, av)))
		return (ft_putstr_r0("Error\n"));
	lets_play(push);
	if (is_it_good(push))
		return (ft_putstr_r0("OK\n"));
	else
		return (ft_putstr_r0("KO\n"));
}
