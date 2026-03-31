/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:57:22 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/02 21:57:32 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	if (!*b)
		return ;
	ft_push(b, a);
	if (i == 1)
		write (1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int i)
{
	if (!*a)
		return ;
	ft_push(a, b);
	if (i == 1)
		write (1, "pb\n", 3);
}

void	ft_push(t_stack **origin, t_stack **dest)
{
	t_stack	*tmp;

	tmp = (*origin)->next;
	(*origin)->next = *dest;
	*dest = *origin;
	*origin = tmp;
}
