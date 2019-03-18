/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/18 15:05:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
#include <stdio.h>

int		execute_rotation(t_tab **stack, size_t dir)
{
	t_tab	*tmp;

	if (!stack || !*stack)
		return (0);
	tmp = ft_tab_dirth(*stack, dir, 1);
	*stack = tmp;
	return (1);
}

int		execute_swap(t_tab **stack)
{
	t_tab 	*tmp;
	size_t	len;

	len = ft_tabloop_lendir(*stack, 0);
	if (len < 1)
		return (0);
	else if (len == 1)
	{
		execute_rotation(stack, 0);
		return (1);
	}
	ft_tab_cut_loop(*stack, 0);
	tmp = ft_tab_cutone((*stack)->dir[0]);
	ft_tabadd(stack, tmp, 0, 0);
	ft_tabloop_it(*stack, 0);
	return (1);
}

int		execute_push(t_tab **stack_a, t_tab **stack_b)
{
	t_tab	*tmp;

	ft_putendl(__func__);
	if (!stack_a || !*stack_a)
		return (0);
	printf("len a: %zu\nlen b: %zu\n", ft_tabloop_lendir(*stack_a, 0), ft_tabloop_lendir(*stack_b, 0));
	ft_putstr("1\n");
	if (ft_tabloop_lendir(*stack_a, 0) <= 1)
	{
		ft_putstr("1if\n");
		ft_tabadd_start(stack_b, *stack_a, 0);
		*stack_a = NULL;
	}
	else
	{
		ft_putstr("1else\n");
		if (!stack_b)
			stack_b = cnalloc(NULL, sizeof(t_tab*));
		execute_rotation(stack_a, 2);
		tmp = ft_tab_cutone((*stack_a)->dir[0]);
		ft_tabadd_start(stack_b, tmp, 0);
		execute_rotation(stack_a, 0);
//		ft_putstr("2if\n");
//		ft_putstr("2rot\n");
//		ft_putstr("2addstart\n");
	}
//	ft_putstr("end\n");
//	ft_wait_pls(0);
//	ft_wait_pls(0);
	return (1);
}

int		execute_double(t_push_swap *push, int mode)
{
	int		r_val;

	r_val =0;
	if (mode == 0)
	{
		r_val += execute_swap(&push->stack_a);
		r_val += execute_swap(&push->stack_b);
	}
	if (mode == 1)
	{
		r_val += execute_rotation(&push->stack_a, 0);
		r_val += execute_rotation(&push->stack_b, 0);
	}
	if (mode == 2)
	{
		r_val += execute_rotation(&push->stack_a, 2);
		r_val += execute_rotation(&push->stack_b, 2);
	}
	if (r_val != 2)
		return (0);
	return (1);
}

int		execute_order_66(t_push_swap *push)
{
//	ft_putendl(__func__);
	if (push->instruction[0] == ' ')
	{
		ft_memmove(push->instruction, &push->instruction[1], ft_strlen(push->instruction));
		CLEAR_SCREEN
	}
	if (!ft_strcmp(push->instruction, "sa"))
		execute_swap(&push->stack_a);
	else if (!ft_strcmp(push->instruction, "sb"))
		execute_swap(&push->stack_b);
	else if (!ft_strcmp(push->instruction, "ss"))
		execute_double(push, 0);

	else if (!ft_strcmp(push->instruction, "pa"))
	{
		if (push->size_a)
		{
			if (execute_push(&push->stack_a, &push->stack_b))
			{
				push->size_a--;
				push->size_b++;
			}
		}
	}
	else if (!ft_strcmp(push->instruction, "pb"))
	{
		if (push->size_b)
		{
			if (execute_push(&push->stack_b, &push->stack_a))
			{
				push->size_a++;
				push->size_b--;
			}
		}
	}

	else if (!ft_strcmp(push->instruction, "ra"))
		execute_rotation(&push->stack_a, 0);
	else if (!ft_strcmp(push->instruction, "rb"))
		execute_rotation(&push->stack_b, 0);
	else if (!ft_strcmp(push->instruction, "rr"))
		execute_double(push, 1);

	else if (!ft_strcmp(push->instruction, "rra"))
		execute_rotation(&(push->stack_a), 2);
	else if (!ft_strcmp(push->instruction, "rrb"))
		execute_rotation(&push->stack_b, 2);
	else if (!ft_strcmp(push->instruction, "rrr"))
		execute_double(push, 2);
	else if (!ft_strcmp(push->instruction, "cs"))
			CLEAR_SCREEN
	else
		return (0);
//	ft_putstr_color("quit 66\n", -1, -1, -1);
	return(1);
}

int		lets_play(t_push_swap *push)
{
	print_push_swap(push);
	if (0 >= get_next_line(0, &push->instruction))
		return (-1);
	while (push->instruction[0] != '\0')
	{
//		ft_putendl(__func__);
//		ft_putstr_color("bef 66\n", -1, -1, -1);
//		ft_wait_pls(0);
		if (!(execute_order_66(push)))
			return (-1);
//		ft_putstr_color("aft 66\n", -1, -1, -1);
//		ft_wait_pls(0);
		push->count++;
//		ft_putstr_color("bef print\n", -1, -1, -1);
//		ft_wait_pls(0);
//		CLEAR_SCREEN
		print_push_swap(push);
//		ft_putstr_color("aft print\n", -1, -1, -1);
//		ft_wait_pls(0);
		ft_strdel(&push->instruction);
//		ft_putstr_color("WE ARE BEF\n", -1, -1, -1);
//		ft_wait_pls(0);
		if (0 >= get_next_line(0, &push->instruction))
			return (-1);
//		ft_putstr_color("WE ARE AFT\n", -1, -1, -1);
//		ft_wait_pls(0);
	}
	return (push->count);
}
