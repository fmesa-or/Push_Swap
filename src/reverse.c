/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:05:50 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/02 22:13:54 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, int i)
{
	t_stack	*tmp;
	int		j;

	if (!a || !((*a)->next))
		return ;
	j = 0;
	tmp = *a;
	while ((*a)->next)
	{
		(*a) = (*a)->next;
		j++;
	}
	(*a)->next = tmp;
	while (j > 1)
	{
		tmp = tmp->next;
		j--;
	}
	tmp->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*tmp;
	int		j;

	if (!b || !((*b)->next))
		return ;
	j = 0;
	tmp = *b;
	while ((*b)->next)
	{
		(*b) = (*b)->next;
		j++;
	}
	(*b)->next = tmp;
	while (j > 1)
	{
		tmp = tmp->next;
		j--;
	}
	tmp->next = NULL;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
