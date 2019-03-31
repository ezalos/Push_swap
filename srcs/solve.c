/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 03:07:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		do_it_yourself(void)
{
	t_push_swap		*push;
	char			*line;
	int				nb;

	push = *ft_remember_push();
	print_push_swap(push);
	ft_putstr("exe:");
	if (0 >= get_next_line(0, &line))
		return (-1);
	while (line[0] != '\0')
	{
		if (line[1] != '\0')
			nb = ft_atoi(line + 1);
		else
			if (line[0] == 'a')
				nb = push->size_a;
			else
				nb = push->size_b;
		ft_printf("  %d   ", nb);
		if (line[0] == 'a')
			ab(nb);
		else
			ba(nb);
		print_push_swap(push);
		ft_strdel(&line);
		ft_putstr("exe:");
		if (0 >= get_next_line(0, &line))
			return (-1);
	}
	if (push->size_b == 1)
		pb();
	return (push->count);
}

void		print_menu(void)
{
	C_ORANGE
	ft_putstr("\t0  : BUBBLE\n");
	ft_putstr("\t1  : WRITE\n");
	ft_putstr("\t2  : MARLEY\n");
	ft_putstr("\t3  : DUMB\n");
	ft_putstr("\t4  : THINK\n");
	C_BLUE
	ft_putstr("\tPlease enter your selection :\t");
	C_RESET
}

int		choose_solve(void)
{
	char *instructions;
	int choice;
	t_push_swap		*push;

	push = (*ft_remember_push());
	print_menu();
	C_CYAN
	if (-1 == get_next_line(0, &instructions))
		return (-1);
	C_RESET
	CLEAR_SCREEN
	choice = 1;
	choice = ft_atoi(instructions);
	if (choice == 0)
		bubble_it();//work
	else if (choice == 1)
		do_it_yourself();//work
	else if (choice == 2)
		algo_tro_bo1(push);
	else if (choice == 3)
		not_smart();
	else if (choice == 4)
		algo_tro_bo2(push);
	ft_strdel(&instructions);
	print_push_swap(push);
	return (0);
}

int		lets_solve(t_push_swap *push)
{
	// char			*line;

	*ft_remember_push() = push;
	choose_solve();
	return (push->count);
}
