/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_write_it_yourself.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 16:00:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int				write_it_yourself(t_push_swap *push)
{
	int			r_v;

	if (VISUAL_MODE)
		print_push_swap(push);
	if (0 >= get_next_line(0, &push->instruction))
		return (-1);
	while (push->instruction[0] != '\0')
	{
		if (-1 == (r_v = execute_order_66(push)))
			return (-1);
		if (r_v)
			push->count++;
		if (!(push->count % 100))
			ft_printf("%d\n", push->count);
		if (VISUAL_MODE)
			print_push_swap(push);
		ft_strdel(&push->instruction);
		if (0 >= get_next_line(0, &push->instruction))
			return (-1);
	}
	return (push->count);
}
