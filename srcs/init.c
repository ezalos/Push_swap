/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:56:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 18:05:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		**setup_tab(int ac, char **av)
{
	int		j;
	int		i;
	int		**to_order;

	if (!(to_order = (int**)malloc(sizeof(int*) * 2)))
		return (NULL);
	if (!(to_order[0] = (int*)malloc(sizeof(int) * (ac + 1))))
		return (NULL);
	if (!(to_order[1] = (int*)malloc(sizeof(int) * (ac + 1))))
		return (NULL);
	i = -1;
	//ft_putstr("\tac = ");
	//ft_putnbr(ac);
	while (++i < ac)
	{
	//	ft_putstr("\n\t\t");
		j = -1;
		while (av[i + 1][++j])
			if (!ft_isdigit(av[i + 1][0]))
				return (NULL);
		to_order[0][i] = ft_atoi(av[i + 1]);
		to_order[1][i] = 0;
	//	ft_putnbr(to_order[0][i]);
	//	ft_putstr("\t");
	//	ft_putnbr(to_order[1][i]);
	}
	//ft_putstr("\n");
	return (to_order);
}
