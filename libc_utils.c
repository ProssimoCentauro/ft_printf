/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:15:29 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/27 15:15:30 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		return (ft_putstr(FT_NULL_STR));
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		count++;
	}
	if (n >= 10)
		count = ft_putnbr(n / 10, count);
	ft_putchar((n % 10) + '0');
	count++;
	return (count);
}
