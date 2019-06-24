/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 19:12:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void		print_menu(void)
{
	_C_ORANGE;
	ft_putendl("");
	ft_putstr("\t0  : QUICK\n");
	ft_putstr("\t1  : WRITE AB_BA\n");
	ft_putstr("\t2  : WRITE ACTIONS\n");
	ft_putstr("\t3  : BUBBLE\n");
	ft_putstr("\t3  : INSERT\n");
	_C_BLUE;
	ft_putstr("\tPlease enter your selection :\t");
	_C_RESET;
}

static int		insert_it(void)
{
	int			last;
	int			temp;

	last = 0;
	if (!order_a((*ft_remember_push())->size_a))
	{
		temp = ab((*ft_remember_push())->size_a);
		if (temp)
			last = temp;
		print_push_swap((*ft_remember_push()));
		insert_it();
	}
	if (last)
		ft_insert_push_ba(-last);
	return (1);
}

static int		choose_solve(int choice)
{
	t_push_swap		*push;

	push = (*ft_remember_push());
	if (choice == 0)
		the_choosen_alg(push);
	else if (choice == 1)
		do_it_yourself();
	else if (choice == 2)
		write_it_yourself(*ft_remember_push());
	else if (choice == 3)
		bubble_it();
	else if (choice == 4)
		insert_it();
	print_push_swap(push);
	return (0);
}

int				lets_solve(t_push_swap *push)
{
	char			*instructions;
	int				choice;

	*ft_remember_push() = push;
	if (VISUAL_MODE)
		print_push_swap(push);
	choice = 0;
	if (CHOOSE_ALG)
		if (VISUAL_MODE)
		{
			print_menu();
			_C_CYAN;
			if (-1 == get_next_line(0, &instructions))
				return (-1);
			_C_RESET;
			_CLEAR_SCREEN;
			choice = ft_atoi(instructions);
			ft_strdel(&instructions);
		}
	choose_solve(choice);
	return (push->count);
}
