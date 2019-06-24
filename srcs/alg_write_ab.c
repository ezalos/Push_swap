/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_write_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:32:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 13:50:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		do_it_yourself(void)
{
	t_push_swap		*push;
	char			*line;

	push = *ft_remember_push();
	print_push_swap(push);
	ft_putstr("exe:");
	if (0 >= get_next_line(0, &line))
		return (-1);
	while (line[0] != '\0')
	{
		if (line[1] != '\0')
			(line[0] == 'a') ? (ab(ft_atoi(line + 1)))
			: (ba(ft_atoi(line + 1)));
		else
			(line[0] == 'a') ? (ab(push->size_a)) : (ba(push->size_b));
		print_push_swap(push);
		ft_strdel(&line);
		ft_putstr("exe:");
		if (0 >= get_next_line(0, &line))
			return (-1);
	}
	while (push->size_b)
		pb();
	return (push->count);
}
