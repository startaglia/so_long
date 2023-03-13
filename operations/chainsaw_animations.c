/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainsaw_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:40:06 by startagl          #+#    #+#             */
/*   Updated: 2023/03/09 15:34:02 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_obstacles_above(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == '1')
		|| (game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == 'L')
		|| (game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == 'R')
		|| (game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == 'C')
		|| (game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == 'E'))
		return (1);
	else
		return (0);
}

int	check_obstacles_below(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.w_sprite.y + 1]
			[game_s->asset.w_sprite.x] == '1')
		|| (game_s->map.map[game_s->asset.w_sprite.y + 1]
			[game_s->asset.w_sprite.x] == 'L')
		|| (game_s->map.map[game_s->asset.w_sprite.y + 1]
			[game_s->asset.w_sprite.x] == 'R')
		|| (game_s->map.map[game_s->asset.w_sprite.y + 1]
			[game_s->asset.w_sprite.x] == 'C')
		|| (game_s->map.map[game_s->asset.w_sprite.y + 1]
			[game_s->asset.w_sprite.x] == 'E'))
		return (1);
	else
		return (0);
}

void	chainsaw_move_up(t_game *game_s)
{
	if (game_s->map.map[game_s->asset.w_sprite.y - 1]
		[game_s->asset.w_sprite.x] == '1'
		&& game_s->asset.w_sprite.move_up == 1)
	{
		game_s->asset.w_sprite.move_up = 0;
		return ;
	}
	else if (game_s->asset.w_sprite.move_up == 1)
	{
		if (check_obstacles_above(game_s))
			game_s->asset.w_sprite.move_up = 0;
		else if (game_s->map.map[game_s->asset.w_sprite.y - 1]
			[game_s->asset.w_sprite.x] == 'P')
			kill_player(game_s);
		else
		{
			game_s->asset.w_sprite.y -= 1;
			move_w_sprite_up(game_s);
		}
	}
}

void	chainsaw_move_down(t_game *game_s)
{
	if (check_obstacles_below(game_s))
		game_s->asset.w_sprite.move_up = 1;
	else if (game_s->map.map[game_s->asset.w_sprite.y + 1]
		[game_s->asset.w_sprite.x] == 'P')
		kill_player(game_s);
	else
	{
		game_s->asset.w_sprite.y += 1;
		move_w_sprite_down(game_s);
	}
}
