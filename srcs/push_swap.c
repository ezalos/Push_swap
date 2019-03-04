/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:43:29 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_swap(int *stack, size_t size)
{
	int		swap;

	if (size >= 2)
	{
		swap = stack[0];
		stack[0] = stack[1];
		stack[1] = swap;
		return (1);
	}
	return (0);
}

int		move_stack(int *stack, size_t size, int direction)
{
	size_t	i;

	if (direction)
	{
		i = size + 1;
		while (--i)
			stack[i] = stack[i - 1];
		size++;
		return (size - 1);
	}
	else
	{
		i = 0;
		while (++i < size)
			stack[i - 1] = stack[i];
		size--;
		return (-i);
	}
}

int		execute_push(t_push_swap *push, int mode)
{
	int		r_val;

	r_val =0;
	if (mode == 0)
	{
		if (push->size_a < 1)
			return (0);
		move_stack(push->stack_b, push->size_b, 1);
		push->stack_b[0] = push->stack_a[0];
		move_stack(push->stack_a, push->size_a, 0);
		push->size_a--;
		push->size_b++;
	}
	if (mode == 1)
	{
		if (push->size_b < 1)
			return (0);
		move_stack(push->stack_a, push->size_a, 1);
		push->stack_a[0] = push->stack_b[0];
		move_stack(push->stack_b, push->size_b, 0);
		push->size_b--;
		push->size_a++;
	}
	return (1);
}

int		execute_rotation(int *stack, size_t size, int reverse)
{
	int		swap;
	size_t	i;

	if (size < 2)
		return (0);
	if (!reverse)
	{
		i = 0;
		swap = stack[0];
		while (++i < size)
			stack[i - 1] = stack[i];
		stack[i - 1] = swap;
	}
	else
	{
		i = size;
		swap = stack[size - 1];
		while (--i >= 1)
			stack[i] = stack[i - 1];
		stack[0] = swap;
	}
	return (1);
}

int		execute_double(t_push_swap *push, int mode)
{
	int		r_val;

	r_val =0;
	if (mode == 0)
	{
		r_val += execute_swap(push->stack_a, push->size_a);
		r_val += execute_swap(push->stack_b, push->size_b);
	}
	if (mode == 1)
	{
		r_val += execute_rotation(push->stack_a, push->size_a, 0);
		r_val += execute_rotation(push->stack_b, push->size_b, 0);
	}
	if (mode == 2)
	{
		r_val += execute_rotation(push->stack_a, push->size_a, 1);
		r_val += execute_rotation(push->stack_b, push->size_b, 1);
	}
	if (r_val != 2)
		return (0);
	return (1);
}

int		execute_order_66(t_push_swap *push)
{
	if (!ft_strcmp(push->instruction, "sa"))
		execute_swap(push->stack_a, push->size_a);
	else if (!ft_strcmp(push->instruction, "sb"))
		execute_swap(push->stack_b, push->size_b);
	else if (!ft_strcmp(push->instruction, "ss"))
		execute_double(push, 0);

	else if (!ft_strcmp(push->instruction, "pa"))
		execute_push(push, 0);
	else if (!ft_strcmp(push->instruction, "pb"))
		execute_push(push, 1);

	else if (!ft_strcmp(push->instruction, "ra"))
		execute_rotation(push->stack_a, push->size_a, 0);
	else if (!ft_strcmp(push->instruction, "rb"))
		execute_rotation(push->stack_b, push->size_b, 0);
	else if (!ft_strcmp(push->instruction, "rr"))
		execute_double(push, 1);

	else if (!ft_strcmp(push->instruction, "rra"))
		execute_rotation(push->stack_a, push->size_a, 1);
	else if (!ft_strcmp(push->instruction, "rrb"))
		execute_rotation(push->stack_b, push->size_b, 1);
	else if (!ft_strcmp(push->instruction, "rrr"))
		execute_double(push, 2);

	else
		return (0);
	return(1);
}

int		lets_play(t_push_swap *push)
{
	print_push_swap(push);
	if (0 >= get_next_line(0, &push->instruction))
		return (-1);
	while (push->instruction[0] != '\0')
	{
		if (!(execute_order_66(push)))
			return (-1);
		push->count++;
		print_push_swap(push);
		ft_strdel(&push->instruction);
		if (0 >= get_next_line(0, &push->instruction))
			return (-1);
	}
	return (push->count);
}
