/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:55:00 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 14:16:15 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************************************
*Checks if we have a duplicated number*
**************************************/
int	ft_checkdup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

/******************************
*Checks if the list is sorted.*
******************************/
int	ft_checksorted(t_stack *stack)
{
	int	tmp;

	tmp = stack->nbr;
	while (stack)
	{
		if (tmp > stack->nbr)
			return (0);
		tmp = stack->nbr;
		stack = stack->next;
	}
	return (1);
}
