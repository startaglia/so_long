/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:56:38 by startagl          #+#    #+#             */
/*   Updated: 2023/02/16 16:08:05 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *ptr, ...);
int		ft_putchar(char c);
size_t	ft_len(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_x(unsigned int nb, const char ptr);
int		ft_putnbr_p(uintptr_t nb);

#endif