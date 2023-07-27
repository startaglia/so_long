/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:02:20 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 16:02:57 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_format_map(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while (1)
	{
		if (str[i] == 'r')
			i--;
		if (str[i] == 'e')
			i--;
		if (str[i] == 'b')
			i--;
		if (str[i] == '.')
			return ;
		ft_printf("Invalid format map\n");
		ft_printf("Error\n");
		exit(1);
	}
}
