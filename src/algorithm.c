/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:31:53 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/08/05 20:31:30 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************
*Checks if the string only contains a simbol '+' or '-'*
*******************************************************/
void	ft_not_digit(const char *str, t_stack **stack, char **array)
{
	if ((str[0] == '+' || str[0] == '-') && !str[1])
		throw_err(stack, array);
}

/***********************************
*Translates the *char input to int *
***********************************/
int	ft_atoi2(const char *str, t_stack **stack, char **array)
{
	long long int	n;
	int				neg;

	n = 0;
	neg = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	ft_not_digit(str, stack, array);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			throw_err(stack, array);
		n = n * 10 + (*str - 48);
		str++;
	}
	if ((n * neg) > INT_MAX || (n * neg) < INT_MIN)
		throw_err(stack, array);
	return (n * neg);
}

/******************************************************************
*Splits the argv if it's given betwen ""                          *
*Converts the char to int                                         *
*Creates a new node at the end of the stack and assigns the number*
******************************************************************/
t_stack	*ft_subprocess(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i], &a, tmp);
		ft_addback(&a, ft_stacknew(j, &a));
		i++;
	}
	if (tmp)
		ft_freearray(tmp);
	return (a);
}

/***************************************
*HERE WE STORE THE NUMBERS IN THE STACK*
***************************************/
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argv[1] == NULL || ft_strlen(argv[1]) == 0)
		throw_err(&a, NULL);
	if (argc == 2)
		a = ft_subprocess(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i], &a, NULL);
			ft_addback(&a, ft_stacknew(j, &a));
			i++;
		}
	}
	return (a);
}
