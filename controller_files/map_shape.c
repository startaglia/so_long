/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:42:00 by startagl          #+#    #+#             */
/*   Updated: 2023/03/07 16:32:22 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_shape(t_game *game_struct)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (game_struct->map.map[0][i])
		i++;
	while (j < game_struct->map.rows)
	{
		k = 0;
		while (game_struct->map.map[j][k])
			k++;
		if (k != i)
		{
			i = 0;
			ft_printf("\nINVALID SHAPE\n");
			ft_printf("\nError\n");
			ft_free_mem(game_struct);
			exit(0);
		}
		j++;
	}
}
