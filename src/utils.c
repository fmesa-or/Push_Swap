/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:08:46 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 15:35:42 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************
*Finds the trhee biggest numbers in the stack and returns the smallest of them*
******************************************************************************/
int	ft_big_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = INT_MIN;
	second = INT_MIN;
	third = INT_MIN;
	while (a)
	{
		if (a->nbr > first)
		{
			third = second;
			second = first;
			first = a->nbr;
		}
		else if (a->nbr > second)
		{
			third = second;
			second = a->nbr;
		}
		else if (a->nbr > third)
			third = a->nbr;
		a = a->next;
	}
	return (third);
}

/***************************************
*Returns the bigger number in the stack*
***************************************/
int	ft_max(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

/****************************************
*Returns the smaller number in the stack*
****************************************/
int	ft_min(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

/*****************************************************
*Finds the NATURAL position of the numbers in A and B*
*****************************************************/
void	ft_positioninator(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pstn = i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pstn = i++;
		b = b->next;
	}
}
