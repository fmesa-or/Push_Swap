/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:37:43 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 20:31:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************************************************************
*Prints in the error output the Error message followed by a \n*
*Then ends the program.                                       *
**************************************************************/
void	throw_err(t_stack **stack, char **array)
{
	write (2, "Error\n", 6);
	if (array)
		ft_freearray(array);
	if (*stack)
		ft_free (stack);
	exit(1);
}
