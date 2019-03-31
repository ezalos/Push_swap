/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/31 01:04:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../../libft/includes/libft.h"

typedef struct		s_push_swap
{
	t_tab			*stack_a;
	t_tab			*stack_b;
//	int				*stack_a;
//	int				*stack_b;
	char			*instruction;
	size_t			all;
	size_t			size_a;
	size_t			size_b;
	int				count;
}					t_push_swap;

t_push_swap	*setup_tab(int ac, char **av);
int			is_it_good(t_push_swap *push);
int			print_push_swap(t_push_swap *push);
int			lets_play(t_push_swap *push);
int			lets_solve(t_push_swap *push);

int			execute_rotation(t_tab **stack, size_t dir);
int			execute_swap(t_tab **stack);
int			execute_push(t_tab **stack_a, t_tab **stack_b);
int			execute_double(t_push_swap *push, int mode);
int			extra_push(t_push_swap *push, int a);
int			execute_order_66(t_push_swap *push);

int			get_solve_data(t_push_swap *push, int **solved);


int		order_a(int size);
int		order_b(int size);
int		ft_get_median(t_tab *stack, size_t size);
int		ft_mv(t_push_swap *push, size_t size, int a);
int			stack_a(int i);
int			stack_b(int i);
int		ab(size_t size);
int		ba(size_t size);


void		ba5(void);
void		ba4(void);
void		ba3(void);
void		ba2(void);
void		ba1(void);



t_push_swap		**ft_remember_push(void);
void			pa(void);
void			pb(void);
void			sa(void);
void			sb(void);
void			ra(void);
void			rra(void);
void			rb(void);
void			rrb(void);
void			rr(void);
void			rrr(void);

void	lest_print_recur(int size);
void	lest_print_recur2(int size);
void	lest_print_recur3(int size, int in);


void	not_smart(void);
int		bubble_it(void);
int		algo_tro_bo1(t_push_swap *push);
int		algo_tro_bo2(t_push_swap *push);


#endif
