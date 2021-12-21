/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:48:50 by oabdelha          #+#    #+#             */
/*   Updated: 2021/11/27 16:39:54 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		i += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_hexdecimal(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			len += ft_putchar(nbr + 48);
		else
			len += ft_putchar(nbr + 87);
	}
	if (nbr > 15)
	{
		len += ft_hexdecimal(nbr / 16);
		len += ft_hexdecimal(nbr % 16);
	}
	return (len);
}

int	ft_hedecimal(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			len += ft_putchar(nbr + 48);
		else
			len += ft_putchar(nbr + 55);
	}
	if (nbr > 15)
	{
		len += ft_hedecimal(nbr / 16);
		len += ft_hedecimal(nbr % 16);
	}
	return (len);
}
