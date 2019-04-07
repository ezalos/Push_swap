/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/07 19:01:49 by ldevelle         ###   ########.fr       */
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
	ft_printf("%d", push->count);
	if (is_it_good(push))
	{
		nb = ft_nb_to_a(push->all, 0);
		name = ft_strjoin("./tests/count/", nb);
		ft_strdel(&nb);
		nb = ft_nb_to_a(push->count, 0);
		ft_add_to_file(name, nb);
		ft_strdel(&nb);
		ft_strdel(&name);
		return (ft_putstr_r0("\nOK\n"));
	}
	else
	{
		fd = open("./tests/KO", O_RDWR);
		size = 0;
		while (++size < (size_t)ac)
			ft_printf("%~.*%~%s ", fd, av[size]);
		return (ft_putstr_r0("\nKO\n"));
	}
}
