/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:26:22 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 14:22:13 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************************************************
* Finds the stack that has the smallest total cost*
**************************************************/
t_stack	*ft_cheaper(t_stack *b)
{
	t_stack	*cheaper;

	cheaper = b;
	while (b)
	{
		if (b->cost_t < cheaper->cost_t)
			cheaper = b;
		b = b->next;
	}
	return (cheaper);
}

/***********************************************************
*This TWO functions calculates the total cost of each stack*
***********************************************************/
void	ft_sum_cost_2(t_stack *b)
{
	if (b->cost_a > 0 && b->cost_b < 0)
		b->cost_t = b->cost_a + (b->cost_b * -1);
	else if (b->cost_a < 0 && b->cost_b > 0)
		b->cost_t = (b->cost_a * -1) + b->cost_b;
}

void	ft_sum_cost(t_stack *b)
{
	if (b->cost_a == 0 && b->cost_b == 0)
		b->cost_t = 0;
	else if (b->cost_a >= 0 && b->cost_b >= 0)
	{
		if (b->cost_a >= b->cost_b)
			b->cost_t = b->cost_a;
		if (b->cost_a < b->cost_b)
			b->cost_t = b->cost_b;
	}
	else if (b->cost_a <= 0 && b->cost_b <= 0)
	{
		if (b->cost_a <= b->cost_b)
			b->cost_t = b->cost_a * -1;
		if (b->cost_a > b->cost_b)
			b->cost_t = b->cost_b * -1;
	}
	else
		ft_sum_cost_2(b);
}

/************************************************************************
*Calculates the cost of the number in stack B and the cost of his target*
************************************************************************/
void	ft_cost_calc(t_stack *b, t_stack *a)
{
	t_stack	*tmpb;

	tmpb = b;
	while (b)
	{
		if (b->target - 1 <= ft_stcksize(a) / 2)
			b->cost_a = b->target - 1;
		if (b->target - 1 > ft_stcksize(a) / 2)
			b->cost_a = (b->target - 1) - ft_stcksize(a);
		if (b->pstn <= (ft_stcksize(tmpb) / 2))
			b->cost_b = b->pstn;
		if (b->pstn > (ft_stcksize(tmpb) / 2))
			b->cost_b = b->pstn - ft_stcksize(tmpb);
		ft_sum_cost(b);
		b = b->next;
	}
}

/****************************************
*Finds over which number of stack A it's*
going to be send each number of stack B.*
****************************************/
void	ft_target_aim(t_stack *a, t_stack *b)
{
	t_stack		*tmpa;
	long long	mem;

	while (b)
	{
		tmpa = a;
		mem = INT_MAX;
		mem++;
		while (tmpa)
		{
			if (b->nbr < tmpa->nbr && tmpa->nbr < mem)
			{
				mem = tmpa->nbr;
				b->target = (tmpa->pstn + 1);
			}
			tmpa = tmpa->next;
		}
		b = b->next;
	}
}
