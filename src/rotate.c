/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:58:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 14:17:22 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !((*a)->next))
		return ;
	tmp = *a;
	last = ft_stcklast(*a);
	(*a) = (*a)->next;
	last->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*lst;

	if (!b || !((*b)->next))
		return ;
	tmp = *b;
	lst = ft_stcklast(*b);
	(*b) = (*b)->next;
	lst->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
