/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:41:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 14:53:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		is_it_good(int **to_order, size_t size)
{
	int		good;
	size_t	i;

	i = 0;
	good = to_order[0][i];
	while (++i < size)
	{
		if (to_order[0][i] <= good)
			return (0);
		good = to_order[0][i];
	}
	return (1);
}
