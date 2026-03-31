/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:19:53 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 15:50:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

	/* COLORS */
# define RD		"\033[1;91m"
# define GR		"\033[0;92m"
# define CRESET	"\033[0m"

	/* STRUCTURE */
typedef struct s_stack
{
	long			nbr;
	int				pstn;
	int				target;
	int				cost_a;
	int				cost_b;
	int				cost_t;
	struct s_stack	*next;
}	t_stack;

	/****FUNCTIONS****/

	/* MAIN */
void	ft_finisher(t_stack **a);
t_stack	*ft_process(int argc, char **argv);
void	ft_send_home(t_stack **a, t_stack **b, t_stack *cheaper);
void	ft_send_home_2(t_stack **a, t_stack **b, t_stack *cheaper);
void	ft_sort(t_stack **a);
void	ft_sort_big(t_stack **a, t_stack *b);
void	ft_sort_three(t_stack **stack);

	/* SORT_BIG UTILS */
t_stack	*ft_cheaper(t_stack *b);
void	ft_cost_calc(t_stack *b, t_stack *a);
void	ft_sum_cost(t_stack *b);
void	ft_sum_cost_2(t_stack *b);
void	ft_target_aim(t_stack *a, t_stack *b);

	/* OPERATIONS */
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);
void	ft_push(t_stack **origin, t_stack **dest);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rr(t_stack **a, t_stack **b, int i);
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);
void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);

	/* UTILS */
void	throw_err(t_stack **stack, char **array);
void	ft_free(t_stack **stack);
void	ft_freearray(char **array);
int		ft_atoi2(const char *str, t_stack **stack, char **array);
int		ft_big_three(t_stack *a);
int		ft_max(t_stack *stack);
int		ft_min(t_stack *stack);
void	ft_not_digit(const char *str, t_stack **stack, char **array);
void	ft_positioninator(t_stack *a, t_stack *b);

	/* STACK UTILS */
void	ft_addback(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int content, t_stack **stack);
t_stack	*ft_stcklast(t_stack *stack);
int		ft_stcksize(t_stack *stack);

	/* CHECKERS */
int		ft_checkdup(t_stack *stack);
int		ft_checksorted(t_stack *stack);

#endif