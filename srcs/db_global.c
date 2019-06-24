/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:58:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/04 14:27:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_push_swap		**ft_remember_push(void)
{
	static t_push_swap		*push;

	return (&push);
}

int				*ft_sent_count(void)
{
	static int		sent;

	return (&sent);
}
