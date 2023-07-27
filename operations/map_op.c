/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:28:07 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 12:44:16 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	preload_map(t_game *game_s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game_s->map.rows)
	{
		j = -1;
		while (++j < game_s->map.cols)
		{
			if (game_s->map.map[i][j] == 'P')
			{
				game_s->asset.sprite.p_x = j;
				game_s->asset.sprite.p_y = i;
			}
			if (game_s->map.map[i][j] == '1')
				put_wall(game_s, i, j);
			else
				put_back(game_s, i, j);
		}
	}
}

void	load_en(t_game	*game_s, int i, int j)
{
	if (game_s->map.map[i][j] == 'L')
	{
		game_s->asset.lp_sprite.x = j;
		game_s->asset.lp_sprite.y = i;
		police_man_control(game_s);
	}
	if (game_s->map.map[i][j] == 'W')
	{
		if (game_s->map.map[i][j])
		game_s->asset.w_sprite.x = j;
		game_s->asset.w_sprite.y = i;
		put_chsaw_en(game_s, game_s->asset.w_sprite.y,
			game_s->asset.w_sprite.x);
	}
}

void	load_tile(t_game	*game_s, int i, int j)
{
	if (game_s->map.map[i][j] == 'C')
	{
		put_tile_c(game_s, i, j);
		if (!game_s->start_flag)
			game_s->asset.clct.coint_c++;
	}
	if (game_s->map.map[i][j] == 'E')
	{
		// game_s->asset.exit.x = j;
		// game_s->asset.exit.y = i;
		put_tile_ex(game_s, i, j);
	}
}

void	load_map(t_game *game_s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game_s->map.rows)
	{
		j = -1;
		while (++j < game_s->map.cols)
		{
			if (game_s->map.map[i][j] == 'P')
				put_r_sprite_frame0 (game_s, i, j);
			load_en(game_s, i, j);
			load_tile(game_s, i, j);
		}
	}
	check_w_on_col(game_s, game_s->asset.lp_sprite.x + 1);
	check_w_on_col(game_s, game_s->asset.lp_sprite.x - 1);
}
