/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/15 13:24:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

/*
** #  define VISUAL_MODE	0	No visual OUTPUT
** #  define VISUAL_MODE	1	Smart Visual OUTPUT
** #  define VISUAL_MODE	2	FULL visual OUTPUT
**
** #  define STEP_BY_STEP	0	No input required
** #  define STEP_BY_STEP	1	Input asked at every print
**
** #  define CHOOSE_ALG		0
** #  define CHOOSE_ALG		1
*/

/*
** # define MODE				0	CORREC	SILENT
** # define MODE				1	CORREC	VERBAL
** # define MODE				2	SOLO	SILENT
** # define MODE				3	SOLO	VERBAL
** # define MODE				4	SOLO	PLAY
*/

# define MODE					0

# if MODE == 0
#  define COUNT					0
#  define PRINT_INSTRUCTIONS	1
#  define CHECKER				0
# elif MODE == 1
#  define VISUAL_CHECKER		2
#  define COUNT					1
#  define SLOW					0
#  define PRINT_INSTRUCTIONS	1
#  define CHECKER				0
#  define JUMP					5
# elif MODE == 2
#  define PROGRESS				0
#  define COUNT					1
# elif MODE == 3
#  define VISUAL_MODE			1
#  define SLOW					1
#  define COUNT					1
#  define PROGRESS				1
# elif MODE == 4
#  define VISUAL_MODE			1
#  define CHOOSE_ALG			1
#  define COUNT					1
# endif

# ifndef CHOOSE_ALG
#  define CHOOSE_ALG		0
# endif
# ifndef VISUAL_CHECKER
#  define VISUAL_CHECKER	0
# endif
# ifndef VISUAL_MODE
#  define VISUAL_MODE		0
# endif
# ifndef PROGRESS
#  define PROGRESS			0
# endif
# ifndef JUMP
#  define JUMP				0
# endif
# ifndef SLOW
#  define SLOW				0
# endif
# ifndef CHECKER
#  define CHECKER			1
# endif
# ifndef PRINT_INSTRUCTIONS
#  define PRINT_INSTRUCTIONS	0
# endif

# define IN_SCREEN			75
# define INSERT_SWITCH		16
# define HITCHHIKER			1
# define STEP_BY_STEP		0
# define FILE_OUTPUT		1

/*
** for 500 switch should be 16~24
** for 100 switch should be	16~24
*/

/*
** # include "../../libft/includes/libft.h"
*/

# include "../libft/includes/libft.h"

typedef struct	s_push_swap
{
	t_tab		*stack_a;
	t_tab		*stack_b;
	char		*instruction;
	size_t		all;
	size_t		size_a;
	size_t		size_b;
	int			count;
	int			save;
	t_tab		*actions;
}				t_push_swap;

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**   INIT	**
**************
*/
t_push_swap		*setup_tab(int ac, char **av);

/*
**************
**   ALG	**
**************
*/
int				bubble_it(void);
int				master_ba(int size);
int				master_ab(int size);
int				the_choosen_alg(t_push_swap *push);
int				do_it_yourself(void);
int				write_it_yourself(t_push_swap *push);
int				ft_insert_push_ba(int size);
int				ft_secial_insert(int size);
int				ft_real_insertion_sort_b(int size);

/*
**************
**   CHECK	**
**************
*/
int				is_it_good(t_push_swap *push);

/*
**************
**    DB	**
**************
*/
int				add_action(char *str);
t_push_swap		**ft_remember_push(void);
int				*ft_sent_count(void);

/*
**************
**   LVL	**
**************
*/

int				execute_order_66(t_push_swap *push);
int				exe_actions(t_push_swap *push);
/*
**   ACTION	**
*/
void			pa(void);
void			sa(void);
void			ra(void);
void			rra(void);
void			pb(void);
void			sb(void);
void			rb(void);
void			rrb(void);
void			rr(void);
void			rrr(void);

/*
**   MEM	**
*/
int				execute_rotation(t_tab **stack, size_t dir);
int				execute_swap(t_tab **stack);
int				execute_push(t_tab **stack_a, t_tab **stack_b);

/*
**   MVT	**
*/
int				execute_double(t_push_swap *push, int mode);
int				extra_push(t_push_swap *push, int a);

/*
**************
**   MENU	**
**************
*/
int				lets_solve(t_push_swap *push);

/*
**************
**   OUT	**
**************
*/
void			action_list(void);
int				print_push_swap(t_push_swap *push);
int				ft_save_file_exit_ko(int ac, char **av);
int				ft_save_file_exit_ok(t_push_swap *push, int ac, char **av);
int				ft_save_arguments(char *path, int ac, char **av);
void			print_header(t_push_swap *push);
void			special_color(int in, int now);
int				print_one_stack(t_push_swap *push, int in, int good, int a);
void			print_stacks(t_push_swap *push);
void			visual_checker(t_push_swap *push);

/*
**************
**   TOOL	**
**************
*/

int				ft_mv(t_push_swap *push, size_t size, int a);
int				ba(size_t size);
int				ab(size_t size);
void			ab_3(void);
int				median_a(size_t size);
int				median_b(size_t size);
int				order_a(int size);
int				order_b(int size);
int				stack_a(int i);
int				stack_b(int i);

/*
**************
**   ZIP	**
**************
*/
int				traduction(void);
int				ft_tab_change_two(t_tab *act, char *action);
void			ft_recognize_case(t_tab *action);

#endif
