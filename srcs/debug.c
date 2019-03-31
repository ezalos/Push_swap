/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:32:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 00:33:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"


void	lest_print_recur(int size)
{
	CURSOR_LOAD
	int i = size;
	while (i--)
	ft_printf("   ");
	if ((int)(*ft_remember_push())->size_a < ft_power(2, size))
	C_YELLOW
	else if (!order_a(ft_power(2, size)))
	C_RED
	else
	C_GREEN
	ft_printf("%s(%d) = %d\n", "ban", size, ft_power(2, size));
	C_RESET
	CURSOR_SAVE
	// char *line;
	// get_next_line(0, &line);
}
void	lest_print_recur2(int size)
{
	CURSOR_LOAD
	int i = size;
	while (i--)
	ft_printf("   ");
	C_MAGENTA
	ft_printf(">ab(%d) = %d\n", size, ft_power(2, size));
	C_RESET
	CURSOR_SAVE
	char *line;
	get_next_line(0, &line);
}
void	lest_print_recur3(int size, int in)
{
	CURSOR_LOAD
	int i = size;
	while (i--)
	ft_printf("   ");
	C_CYAN
	if (in == 1)
		ft_printf(">");
	else if (in == 2)
		ft_printf("^");
	else
		ft_printf("<");
	ft_printf("ba(%d) = %d\n", size, ft_power(2, size));
	C_RESET
	CURSOR_SAVE
	char *line;
	get_next_line(0, &line);
}
