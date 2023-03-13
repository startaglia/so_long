/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:09:31 by startagl          #+#    #+#             */
/*   Updated: 2023/03/09 14:38:46 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	refresh_string(t_game *game_s)
{
	put_wall(game_s, 0, 0);
	mlx_string_put(game_s->window.mlx, game_s->window.win,
		10, 10, 0x83F01A, game_s->asset.sprite.steps_str);
}
