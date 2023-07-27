/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:19:18 by startagl          #+#    #+#             */
/*   Updated: 2023/02/16 16:08:30 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_len(s));
	return (ft_len(s));
}

int	ft_operations(va_list list, const char ptr)
{
	int	bytes;

	bytes = 0;
	if (ptr == 'c')
		bytes += ft_putchar(va_arg(list, int));
	else if (ptr == 's')
		bytes += ft_putstr(va_arg(list, char *));
	else if (ptr == 'd' || ptr == 'i')
		bytes += ft_putnbr(va_arg(list, int));
	else if (ptr == 'u')
		bytes += ft_putnbr_u(va_arg(list, unsigned int));
	else if (ptr == 'x' || ptr == 'X')
		bytes += ft_putnbr_x(va_arg(list, unsigned int), ptr);
	else if (ptr == 'p')
	{
		bytes += ft_putstr("0x");
		bytes += ft_putnbr_p(va_arg(list, uintptr_t));
	}
	else if (ptr == 37)
		bytes += ft_putchar(37);
	return (bytes);
}

int	ft_printf(const char *ptr, ...)
{
	int		i;
	int		bytes;
	va_list	list;
	int		len;

	va_start(list, ptr);
	i = 0;
	len = 0;
	if (!ptr)
		return (0);
	bytes = 0;
	while (ptr[i])
	{
		if (ptr[i] == 37)
		{
			bytes += ft_operations(list, ptr[i + 1]);
			i++;
		}
		else
			bytes += write(1, &ptr[i], 1);
		i++;
	}
	va_end(list);
	return (bytes);
}

// int main()
// {
// 	char tere;
// 	char *gere;
// 	void *poti;

// 	poti = "ciao";
// 	tere = '0';
// 	gere = "pere";
// 	ft_printf("mine return: %p\n", poti);
// 	printf("real return: %p\n", poti);
// 	return(0);
// }