/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mem_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:09:13 by startagl          #+#    #+#             */
/*   Updated: 2023/03/08 09:11:39 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	str = ft_memset(str, '\0', n);
	return ;
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*ptr;

	if (nmeb == SIZE_MAX && size == SIZE_MAX)
		return (0);
	ptr = malloc((nmeb * size));
	if (!ptr)
		return (0);
	ft_bzero(ptr, (nmeb * size));
	return ((void *)ptr);
}
