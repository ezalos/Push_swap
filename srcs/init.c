/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:56:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 14:40:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void	get_mix(int i, int j, int *mix)
{
	if (i == 0)
	{
		mix[0] = j;
		mix[1] = j;
	}
	else if (j < mix[0])
		mix[0] = j;
	else if (j > mix[1])
		mix[1] = j;
}

static int	scrap_ac(t_push_swap *push, int ac, char **av, int *mix)
{
	int				i;
	int				j;

	i = -1;
	while (++i < ac)
	{
		if (PROGRESS)
			ft_progress("Init", i, ac * 2);
		j = -1;
		if (av[i + 1][0] == '-')
			j++;
		while (av[i + 1][++j])
			if (!ft_isdigit(av[i + 1][j]))
				return (0);
		if (ft_is_str_bigger_than_int(av[i + 1]))
			return (0);
		j = ft_atoi(av[i + 1]);
		get_mix(i, j, mix);
		if (!push->stack_a)
			push->stack_a = ft_tabnew_ptr((int*)&j, sizeof(int));
		else
			ft_tabadd_end(push->stack_a,
				ft_tabnew_ptr((int*)&j, sizeof(int)), 0);
	}
	return (1);
}

int			check_for_double(t_push_swap *push, int *mix)
{
	int		*tab;
	int		i;

	tab = ft_memalloc((mix[1] - mix[0] + 1) * sizeof(int));
	i = -1;
	while (++i < (int)push->size_a)
	{
		if (PROGRESS)
			ft_progress("Init", i, push->size_a);
		if (tab[stack_a(i) - mix[0]] == 0)
			tab[stack_a(i) - mix[0]] = 1;
		else
		{
			ft_memdel((void**)&tab);
			return (-1);
		}
	}
	ft_memdel((void**)&tab);
	return (0);
}

t_push_swap	*setup_tab(int ac, char **av)
{
	t_push_swap		*push;
	int				mix[2];

	if (PROGRESS)
		ft_progress("Init", 0, ac * 2);
	push = (t_push_swap*)cnalloc(NULL, sizeof(t_push_swap));
	push->all = ac;
	push->size_a = push->all;
	push->stack_b = NULL;
	*ft_remember_push() = push;
	if (!scrap_ac(push, ac, av, mix) || (check_for_double(push, mix)))
		return (NULL);
	ft_tabloop_it(push->stack_a, 0);
	if (PROGRESS)
		ft_progress("Init", 1, 1);
	return (push);
}
