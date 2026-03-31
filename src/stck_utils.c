/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:32:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 15:49:01 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***********************
*Creates a new node    *
*Gives to it the number*
***********************/
t_stack	*ft_stacknew(int content, t_stack **stack)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		throw_err(stack, NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

/***********************************
*Returns the last node of the stack*
***********************************/
t_stack	*ft_stcklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/******************************
*Returns the size of the stack*
******************************/
int	ft_stcksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/************************************
*Adds a node to the end of the stack*
************************************/
void	ft_addback(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
		(ft_stcklast(*stack))->next = new;
}
