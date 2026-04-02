/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:49:58 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 16:54:21 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!a || !((*a)->next))
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (i == 1)
		write (1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int i)
{
	t_stack	*tmp;

	if (!b || !((*b)->next))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}