/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:04:25 by startagl          #+#    #+#             */
/*   Updated: 2023/03/08 09:04:58 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_mem(t_game *game_struct)
{
	int	i;

	i = -1;
	while (++i < game_struct->map.rows)
		free(game_struct->map.map[i]);
	free(game_struct->map.map);
}
