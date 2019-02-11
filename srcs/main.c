/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 15:49:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(int ac, char **av)
{
	int		**to_order;
	size_t	size;

	if (ac <= 1)
		return (ft_putstr_r0("Error\n"));
	size = ac - 1;
	if (!(to_order = setup_tab(size, av)))
		return (ft_putstr_r0("Error\n"));
	if (0 > lets_play(to_order, size))
		return (ft_putstr_r0("Error\n"));
	if (is_it_good(to_order, size))
		return (ft_putstr_r0("OK\n"));
	else
		return (ft_putstr_r0("KO\n"));
}
