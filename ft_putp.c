/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:38:02 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/12/10 17:38:04 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	conte(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb < 16)
		return (1);
	else
	{
		while (nb > 15)
		{
			nb = nb / 16;
			i++;
		}
	}
	i = i + 1;
	return (i);
}

void	ft_putp_base(unsigned long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
	{
		ft_putchar(base[nb]);
	}
	else
	{
		ft_putp_base(nb / 16);
		ft_putchar(base[nb % 16]);
	}
}

int	ft_putp(unsigned long nb)
{
	int	a;

	a = conte(nb) + 2;
	write(1, "0x", 2);
	ft_putp_base(nb);
	return (a);
}
