/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_police_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:15:21 by startagl          #+#    #+#             */
/*   Updated: 2023/03/13 09:50:15 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reset_right_shoot(t_game *game_s)
{
	if (game_s->asset.sh_sprite.arrived == 1)
	{
		game_s->asset.sh_sprite.y = game_s->asset.lp_sprite.y;
		game_s->asset.sh_sprite.x = game_s->asset.lp_sprite.x;
		game_s->asset.sh_sprite.x += 1;
		put_shoot_sprite(game_s, game_s->asset.sh_sprite.y,
			game_s->asset.sh_sprite.x);
		game_s->asset.sh_sprite.arrived = 0;
	}	
}

void	turn_policeman_to_right(t_game *game_s)
{
	game_s->asset.lp_sprite.first_shoot_on_side = 0;
	put_back(game_s, game_s->asset.sh_sprite.y,
		game_s->asset.sh_sprite.x);
	if (game_s->asset.lp_sprite.shoot_switch == 0)
	{
		game_s->asset.sh_sprite.y = game_s->asset.lp_sprite.y;
		game_s->asset.sh_sprite.x = game_s->asset.lp_sprite.x;
	}
	game_s->asset.lp_sprite.shoot_switch = 1;
	put_right_police(game_s, game_s->asset.lp_sprite.y,
		game_s->asset.lp_sprite.x);
	shoot_right(game_s);
}

int	whats_on_right(t_game *game_s)
{
	if (game_s->map.map[game_s->asset.lp_sprite.y]
		[game_s->asset.lp_sprite.x + 1] == '1')
	{
		put_wall(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x + 1);
		return (1);
	}
	else if (game_s->map.map[game_s->asset.lp_sprite.y]
		[game_s->asset.lp_sprite.x + 1] == 'E')
	{
		put_tile_ex(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x + 1);
		return (1);
	}
	else if (game_s->map.map[game_s->asset.lp_sprite.y]
		[game_s->asset.lp_sprite.x + 1] == 'C')
	{
		put_tile_c(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x + 1);
		return (1);
	}
	return (0);
}

void	shoot_right(t_game *game_s)
{
	if (game_s->map.map[game_s->asset.lp_sprite.y]
		[game_s->asset.lp_sprite.x + 1] != '0'
		&& game_s->map.map[game_s->asset.lp_sprite.y]
		[game_s->asset.lp_sprite.x + 1] != 'P')
		whats_on_right(game_s);
	else if (where_shoot_could_kill_player(game_s))
		kill_player(game_s);
	else if (check_right_shoot_obstacle(game_s))
	{
		game_s->asset.sh_sprite.arrived = 1;
		put_back(game_s, game_s->asset.sh_sprite.y, game_s->asset.sh_sprite.x);
	}
	else if (game_s->map.map[game_s->asset.sh_sprite.y]
		[game_s->asset.sh_sprite.x] == 'P')
		kill_player(game_s);
	else
	{
		game_s->asset.sh_sprite.x += 1;
		shoot_sprite_r(game_s);
	}
	reset_right_shoot(game_s);
}

int	check_right_shoot_obstacle(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sh_sprite.y]
			[game_s->asset.sh_sprite.x + 1] == '1')
		|| (game_s->map.map[game_s->asset.sh_sprite.y]
			[game_s->asset.sh_sprite.x + 1] == 'C')
		|| (game_s->map.map[game_s->asset.sh_sprite.y]
			[game_s->asset.sh_sprite.x + 1] == 'W')
		|| (game_s->map.map[game_s->asset.sh_sprite.y]
			[game_s->asset.sh_sprite.x + 1] == 'E'))
		return (1);
	return (0);
}
