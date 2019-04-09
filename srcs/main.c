/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/09 20:40:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void		ft_add_to_file(char *name, char *data)
{
	int				fd;

	fd = open(name, O_CREAT|O_RDWR|O_APPEND, S_IRWXU|S_IRWXG|S_IRWXO);
	ft_putendl_fd(data, fd);
	close(fd);
	// return (fd);
}

void    show_it(void)
{
	int size;

	size = -1;
	while (++size < (int)(*ft_remember_push())->all)
		ft_printf("[%d]:%d\n", size, stack_a(size));
	ft_press_any_key();
}

void	action_list(void)
{
	int i;

	i = -1;
	ft_putendl("");
	while (++i < (*ft_remember_push())->count)
		ft_printf("%s ", *(char**)ft_tab_dirth((*ft_remember_push())->actions, 0, i)->content);
	ft_putendl("");
}

int		main(int ac, char **av)
{
	t_push_swap		*push;
	char			*nb;
	char			*name;
	size_t			size;
	int				fd;

	// CLEAR_SCREEN
	if (ac <= 1)
		return (ft_putstr_r0("Error\n"));
	size = ac - 1;
	if (!(push = setup_tab(size, av)))
		return (ft_putstr_r0("Error\n"));
	lets_play(push);
	action_list();
	ft_printf("%d\n", push->count);
	if (is_it_good(push))
	{
		nb = ft_nb_to_a(push->all, 0);
		name = ft_strjoin("./tests/count/", nb);
		ft_strdel(&nb);
		nb = ft_nb_to_a(push->count, 0);
		ft_add_to_file(name, nb);
		ft_strdel(&nb);
		ft_strdel(&name);
		return (ft_putstr_r0("OK\n"));
	}
	else
	{
		fd = open("./tests/KO", O_RDWR);
		size = 0;
		while (++size < (size_t)ac)
			ft_printf("%~.*%~%s ", fd, av[size]);
		return (ft_putstr_r0("KO\n"));
	}
}
