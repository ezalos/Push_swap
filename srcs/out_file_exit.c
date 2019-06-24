/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_file_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:06:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:23:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int		ft_save_file_exit_ok_much(t_push_swap *push, int ac, char **av)
{
	char			*nb;
	char			*name;
	int				i;
	int				fd;

	nb = ft_nb_to_a(push->all, 0);
	name = ft_strjoin_multi(4,
		"./tests/too_much/", nb, "_", ft_nb_to_a(push->count, 0));
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	{
		i = 0;
		while (++i < ac)
		{
			ft_putstr_fd(av[i], fd);
			ft_putstr_fd(" ", fd);
		}
		close(fd);
	}
	ft_strdel(&name);
	ft_strdel(&nb);
	return (1);
}

int				ft_save_file_exit_ok(t_push_swap *push, int ac, char **av)
{
	char			*nb;
	char			*name;

	if ((push->all == 500 && push->count >= 5300)
	|| (push->all == 100 && push->count >= 700))
		ft_save_file_exit_ok_much(push, ac, av);
	nb = ft_nb_to_a(push->all, 0);
	name = ft_strjoin("./tests/count/", nb);
	ft_strdel(&nb);
	nb = ft_nb_to_a(push->count, 0);
	ft_add_to_file(name, nb);
	ft_strdel(&nb);
	ft_strdel(&name);
	print_time();
	return (1);
}

int				ft_save_file_exit_ko(int ac, char **av)
{
	int				i;
	int				fd;

	fd = open("./tests/KO", O_RDWR);
	i = 0;
	while (++i < ac)
		ft_printf("%~.*%~%s ", fd, av[i]);
	print_time();
	return (1);
}

int				ft_save_arguments(char *path, int ac, char **av)
{
	int				i;
	int				fd;

	if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRWXU | S_IRWXG | S_IRWXO)) > 0)
	{
		i = 0;
		while (++i < ac)
		{
			ft_putstr_fd(av[i], fd);
			ft_putstr_fd(" ", fd);
		}
		close(fd);
	}
	return (1);
}
