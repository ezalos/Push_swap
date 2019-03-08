/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/06 17:37:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_rotation(t_tab **stack, size_t dir)
{
	t_tab	*tmp;
//	int		i = 25;
	//int		line;

	tmp = ft_tab_dirth(*stack, dir, 1);

	if (!stack || !*stack)
		return (0);
	//tmp = (*stack)->dir[dir];
/*	line = 10;
	if (dir)
		line += ft_random(0, 8, (int)stack, (int)stack) * 4;
	place_cursor(line, 0);
	ft_rgb_color(-1, -1, -1);
	ft_putendl(__func__);
	ft_putstr("stack bef:\t");
	ft_putnbr(*(int*)(*stack)->content);
	ft_putendl("");
	ft_putstr("next in dir:\t");
	ft_putnbr(*(int*)tmp->content);
	ft_putendl("");


*/
	*stack = tmp;

/*

	ft_putstr("stack aft:\t");
	ft_putnbr(*(int*)(*stack)->content);
	ft_putendl("");
	//while (--i)
		ft_wait_pls(0);*/
//	*stack = tmp;
	return (1);
}

int		execute_swap(t_tab **stack)
{
	t_tab 	*tmp;
	size_t	len;
		ft_putendl(__func__);

	if (ft_tabloop_lendir(*stack, 0) < 2)
	{
		ft_putstr_color("0end swap\n", -1, -1, -1);
		return (0);
	}
	ft_putstr_color("1swap\n", -1, -1, -1);
	tmp = ft_tab_cutone((*stack)->dir[0]);
	len = ft_tabloop_lendir(*stack, 0);
	ft_tab_connect_structs(tmp, *stack, 0);
	ft_putstr_color("@swap\n", -1, -1, -1);
	ft_tab_connect_structs(ft_tab_dirth(*stack, 0, len), tmp, 0);//len is bad
	//ft_tabadd(&(*stack)->dir[2], tmp, 0, 1);
	//ft_putstr_color("2swap\n", -1, -1, -1);
	//ft_tab_connect_structs(tmp, *stack, 0);
	//ft_tab_connect_structs(ft_tab_reach_end(*stack, 0), *stack, 0);
	*stack = (*stack)->dir[2];
	//ft_tab_connect_structs(*stack, (*stack)->dir[0], 0);
	ft_putstr_color("end swap\n", -1, -1, -1);
	return (1);
}

int		execute_push(t_tab **stack_a, t_tab **stack_b)
{
//	ft_putendl(__func__);
	if (!stack_a || !*stack_a)
		return (0);
//	ft_putstr("1\n");
	if (ft_tabloop_lendir(*stack_a, 0) < 2)
	{
//		ft_putstr("1if\n");
		ft_tabadd_start(stack_b, *stack_a, 0);
		*stack_a = NULL;
	}
	else
	{
//		ft_putstr("1else\n");
		if (!stack_b)
			stack_b = cnalloc(NULL, sizeof(t_tab*));
//		ft_putstr("2if\n");
		execute_rotation(stack_a, 2);
//		ft_putstr("2rot\n");
		ft_tabadd_start(stack_b, ft_tab_cutone((*stack_a)->dir[2]), 0);
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
	if (!ft_strcmp(push->instruction, "sa"))
		execute_swap(&push->stack_a);
	else if (!ft_strcmp(push->instruction, "sb"))
		execute_swap(&push->stack_b);
	else if (!ft_strcmp(push->instruction, "ss"))
		execute_double(push, 0);

	else if (!ft_strcmp(push->instruction, "pa"))
	{
		if (execute_push(&push->stack_a, &push->stack_b))
		{
			push->size_a--;
			push->size_b++;
		}
	}
	else if (!ft_strcmp(push->instruction, "pb"))
	{
		if (execute_push(&push->stack_b, &push->stack_a))
		{
			push->size_a++;
			push->size_b--;
		}
	}

	else if (!ft_strcmp(push->instruction, "ra"))
		push->stack_a = push->stack_a->dir[0];
//		execute_rotation(&push->stack_a, 0);
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
