/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:23:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 14:26:08 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***********************************
*Only sorts when are 3 left numbers*
***********************************/
void	ft_sort_three(t_stack **stack)
{
	if (ft_checksorted(*stack))
		return ;
	else if ((*stack)->nbr == ft_min(*stack))
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	else if ((*stack)->nbr == ft_max(*stack))
	{
		ft_ra(stack, 1);
		if (!ft_checksorted(*stack))
			ft_sa(stack, 1);
	}
	else
	{
		if ((ft_stcklast(*stack))->nbr == ft_max(*stack))
			ft_sa(stack, 1);
		else
			ft_rra(stack, 1);
	}
}
