/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:07:04 by startagl          #+#    #+#             */
/*   Updated: 2023/01/31 15:17:40 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		i += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
		i += ft_putnbr(nb);
		return (i);
	}
	else if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr_u(nb / 10);
		i += ft_putnbr_u(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putnbr_x(unsigned int nb, char const ptr)
{
	int	i;

	i = 0;
	if (nb > 15)
	{
		i += ft_putnbr_x((nb / 16), ptr);
		i += ft_putnbr_x((nb % 16), ptr);
	}
	else if (nb > 9)
	{
		if (ptr == 'x')
			i += ft_putchar(nb - 10 + 'a');
		else if (ptr == 'X')
			i += ft_putchar(nb - 10 + 'A');
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putnbr_p(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb > 15)
	{
		i += ft_putnbr_p(nb / 16);
		i += ft_putnbr_p(nb % 16);
	}
	else
	{
		if (nb > 9)
			i += ft_putchar(nb - 10 + 'a');
		else
			i += ft_putchar(nb + 48);
	}
	return (i);
}
