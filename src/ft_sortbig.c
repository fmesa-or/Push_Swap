/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:59:04 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 16:50:18 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****************************************************
*This TWO functions rotates or reverse rotates      *
*the stacks so it can push to A the cheapest number.*
****************************************************/

void	ft_send_home_2(t_stack **a, t_stack **b, t_stack *cheaper)
{
	if (cheaper->cost_a > 0)
	{
		ft_ra(a, 1);
		cheaper->cost_a--;
	}
	else if (cheaper->cost_a < 0)
	{
		ft_rra(a, 1);
		cheaper->cost_a++;
	}
	else if (cheaper->cost_b > 0)
	{
		ft_rb(b, 1);
		cheaper->cost_b--;
	}
	else if (cheaper->cost_b < 0)
	{
		ft_rrb(b, 1);
		cheaper->cost_b++;
	}
}

void	ft_send_home(t_stack **a, t_stack **b, t_stack *cheaper)
{
	while (cheaper->cost_a != 0 || cheaper->cost_b != 0)
	{
		if (cheaper->cost_a > 0 && cheaper->cost_b > 0)
		{
			ft_rr(a, b, 1);
			cheaper->cost_a--;
			cheaper->cost_b--;
		}
		else if (cheaper->cost_a < 0 && cheaper->cost_b < 0)
		{
			ft_rrr(a, b, 1);
			cheaper->cost_a++;
			cheaper->cost_b++;
		}
		else
			ft_send_home_2(a, b, cheaper);
	}
	ft_pa(a, b, 1);
}

/***********************************************************************
*When the stack A is full this functions rotates or reverse rotates the*
*full stack so it's sorted from smallest to biggest from top to bottom.* 
***********************************************************************/
void	ft_finisher(t_stack **a)
{
	t_stack	*min;
	int		i;

	min = *a;
	i = ft_min(*a);
	while (min->nbr != i)
		min = min->next;
	if (min->pstn <= (ft_stcksize(*a) / 2))
		while ((*a)->nbr != min->nbr)
			ft_ra(a, 1);
	else if (min->pstn > (ft_stcksize(*a) / 2))
		while ((*a)->nbr != min->nbr)
			ft_rra(a, 1);
}

void	ft_sort_big(t_stack **a, t_stack *b)
{
	t_stack		*cheaper;
	long long	i;

	i = ft_big_three(*a);
	while (ft_stcksize(*a) > 3)
	{
		if ((*a)->nbr < i)
			ft_pb(a, &b, 1);
		else
			ft_ra(a, 1);
	}
	ft_sort_three(a);
	while (b)
	{
		ft_positioninator(*a, b);
		ft_target_aim(*a, b);
		ft_cost_calc(b, *a);
		cheaper = ft_cheaper(b);
		ft_send_home(a, &b, cheaper);
		ft_target_aim(*a, b);
	}
	ft_positioninator(*a, NULL);
	ft_finisher(a);
}

void	ft_sort(t_stack **a)
{
	t_stack		*b;

	b = NULL;
	if (ft_stcksize(*a) == 2)
		ft_sa(a, 1);
	else if (ft_stcksize(*a) == 3)
		ft_sort_three(a);
	else
		ft_sort_big(a, b);
}
