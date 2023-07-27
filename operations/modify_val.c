/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:09 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 12:43:51 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	modify_val_up(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'L')
		|| (game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'W'))
		kill_player(game_s);
	game_s->map.map[game_s->asset.sprite.p_y + 1]
	[game_s->asset.sprite.p_x] = '0';
	put_back(game_s, game_s->asset.sprite.p_y + 1,
		game_s->asset.sprite.p_x);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x] = 'P';
}

void	modify_val_left(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'L')
		|| (game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'W'))
		kill_player(game_s);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x + 1] = '0';
	put_back(game_s, game_s->asset.sprite.p_y,
		game_s->asset.sprite.p_x + 1);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x] = 'P';
}

void	modify_val_down(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'L')
		|| (game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'W'))
		kill_player(game_s);
	game_s->map.map[game_s->asset.sprite.p_y - 1]
	[game_s->asset.sprite.p_x] = '0';
	put_back(game_s, game_s->asset.sprite.p_y - 1,
		game_s->asset.sprite.p_x);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x] = 'P';
}

void	modify_val_right(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'L')
		|| (game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'W'))
		kill_player(game_s);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x - 1] = '0';
	put_back(game_s, game_s->asset.sprite.p_y,
		game_s->asset.sprite.p_x - 1);
	game_s->map.map[game_s->asset.sprite.p_y]
	[game_s->asset.sprite.p_x] = 'P';
}

void	modify_val(t_game *game_s, int key)
{
	if (key == 13)
	{
		refresh_string(game_s);
		modify_val_up(game_s);
	}
	else if (key == 0)
	{
		refresh_string(game_s);
		modify_val_left(game_s);
	}
	else if (key == 1)
	{
		refresh_string(game_s);
		modify_val_down(game_s);
	}
	else if (key == 2)
	{
		refresh_string(game_s);
		modify_val_right(game_s);
	}
	// if (game_s->asset.clct.coint_c == 0)
	// {
	// 	game_s->map.map[game_s->asset.exit.y][game_s->asset.exit.x] = 'E';
	// 	put_tile_ex(game_s, game_s->asset.exit.y, game_s->asset.exit.x);
	// }
}
