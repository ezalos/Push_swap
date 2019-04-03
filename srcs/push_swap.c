/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/03 19:06:48 by ldevelle         ###   ########.fr       */
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
	tmp = ft_tab_cutone((*stack)->dir[0]);
	ft_tabadd(stack, tmp, 0, 0);
	return (1);
}

int		execute_push(t_tab **stack_a, t_tab **stack_b)
{
	t_tab	*tmp;

	if (!stack_a || !*stack_a)
		return (0);
	if (ft_tabloop_lendir(*stack_a, 0) <= 1)
	{
		// ft_printf("%s-IF: %d\n", __func__, ft_tabloop_lendir(*stack_a, 0));
		ft_tabadd_start(stack_b, *stack_a, 0);
		*stack_a = NULL;
	}
	else
	{
		// ft_printf("%s-ELSE: %d\n", __func__, ft_tabloop_lendir(*stack_a, 0));
		if (!stack_b)
			stack_b = cnalloc(NULL, sizeof(t_tab*));
		// ft_printf("%~{!}\t%~{!}\t%~{!}\n", (*stack_a)->dir[2], (*stack_a), (*stack_a)->dir[0]);
		execute_rotation(stack_a, 2);
		// ft_printf("%~{!}\t%~{!}\t%~{!}\n", (*stack_a)->dir[2], (*stack_a), (*stack_a)->dir[0]);
		tmp = ft_tab_cutone((*stack_a)->dir[0]);
		// ft_printf("%~{!}\n", tmp);
		// ft_printf("%~{!}\t%~{!}\t%~{!}\n", (*stack_a)->dir[2], (*stack_a), (*stack_a)->dir[0]);
		ft_tabadd_start(stack_b, tmp, 0);
		ft_tabloop_it(*stack_b, 0);
		// ft_printf("%~{!}\t%~{!}\t%~{!}\n", (*stack_b)->dir[2], (*stack_b), (*stack_b)->dir[0]);
		execute_rotation(stack_a, 0);
	}
	// ft_printf("end\n");
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

int		extra_push(t_push_swap *push, int a)
{
	if (a)
	{
		if (push->size_a)
			if (execute_push(&push->stack_a, &push->stack_b))
			{
				push->size_a--;
				push->size_b++;
				return (1);
			}
	}
	else
	{
		if (push->size_b)
			if (execute_push(&push->stack_b, &push->stack_a))
			{
				push->size_a++;
				push->size_b--;
				return (1);
			}
	}
	return (0);
}

int		execute_order_66(t_push_swap *push)
{
	if (push->instruction[0] == ' ')
		ft_memmove(push->instruction, &push->instruction[1], ft_strlen(push->instruction));
	// else
	// 	CLEAR_SCREEN
	if (!ft_strcmp(push->instruction, "sa"))
		execute_swap(&push->stack_a);
	else if (!ft_strcmp(push->instruction, "sb"))
		execute_swap(&push->stack_b);
	else if (!ft_strcmp(push->instruction, "ss"))
		execute_double(push, 0);

	else if (!ft_strcmp(push->instruction, "pa"))
		extra_push(push, 1);
	else if (!ft_strcmp(push->instruction, "pb"))
		extra_push(push, 0);

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
	{
		lets_solve(push);
		return (1);
	}
	// print_push_swap(push);
	return(1);
}

int		lets_play(t_push_swap *push)
{
	*ft_remember_push() = push;
	print_push_swap(push);
	// ft_wait_pls(0);
	// ft_wait_pls(0);
	// ft_wait_pls(0);
	lets_solve(push);
/*
** 	if (0 >= get_next_line(0, &push->instruction))
** 		return (-1);
** 	while (push->instruction[0] != '\0')
** 	{
** 		if (!(execute_order_66(push)))
** 			return (-1);
** 		push->count++;
** //		CLEAR_SCREEN
** 		print_push_swap(push);
** 		ft_strdel(&push->instruction);
** 		if (0 >= get_next_line(0, &push->instruction))
** 			return (-1);
** 	}
*/
	return (push->count);
}
