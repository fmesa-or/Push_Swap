/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:11:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/30 10:24:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i += write(1, "(null)", 6);
	else
	{
		while (s[i])
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(long nb, int tempnb, int i)
{
	if (nb < 0)
	{
		nb *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
		i++;
	}
	if (nb > 9)
	{
		tempnb = ft_putnbr(nb / 10, 0, 0);
		if (tempnb == -1)
			return (-1);
		i += tempnb;
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb += 48;
		if (write(1, &nb, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	long	nb;
	int		i;
	int		tempnb;

	i = 0;
	nb = n;
	if (nb > 9)
	{
		tempnb = ft_putnbr_u(nb / 10);
		if (tempnb == -1)
			return (-1);
		i += tempnb;
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb += 48;
		if (write(1, &nb, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
