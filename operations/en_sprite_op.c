/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_sprite_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:25:41 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 16:08:08 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w_sprite_up(t_game *game_s)
{
	game_s->map.map[game_s->asset.w_sprite.y]
	[game_s->asset.w_sprite.x] = 'W';
	put_chsaw_en(game_s, game_s->asset.w_sprite.y, game_s->asset.w_sprite.x);
	game_s->map.map[game_s->asset.w_sprite.y + 1]
	[game_s->asset.w_sprite.x] = '0';
	put_back(game_s, game_s->asset.w_sprite.y + 1, game_s->asset.w_sprite.x);
}

void	move_w_sprite_down(t_game *game_s)
{
	game_s->map.map[game_s->asset.w_sprite.y]
	[game_s->asset.w_sprite.x] = 'W';
	put_chsaw_en(game_s, game_s->asset.w_sprite.y, game_s->asset.w_sprite.x);
	game_s->map.map[game_s->asset.w_sprite.y - 1]
	[game_s->asset.w_sprite.x] = '0';
	put_back(game_s, game_s->asset.w_sprite.y - 1, game_s->asset.w_sprite.x);
}

void	shoot_sprite_l(t_game *game_s)
{
	if (!game_s->asset.lp_sprite.first_shoot_on_side)
	{
		game_s->asset.lp_sprite.first_shoot_on_side = 1;
		put_shoot_sprite(game_s, game_s->asset.sh_sprite.y,
			game_s->asset.sh_sprite.x);
	}
	else
	{
		put_shoot_sprite(game_s, game_s->asset.sh_sprite.y,
			game_s->asset.sh_sprite.x);
		put_back(game_s, game_s->asset.sh_sprite.y, game_s->asset.sh_sprite.x
			+ 1);
	}
}

void	shoot_sprite_r(t_game *game_s)
{
	if (!game_s->asset.lp_sprite.first_shoot_on_side)
	{
		put_shoot_sprite(game_s, game_s->asset.sh_sprite.y,
			game_s->asset.sh_sprite.x);
	}
	else
	{
		put_shoot_sprite(game_s, game_s->asset.sh_sprite.y,
			game_s->asset.sh_sprite.x);
		put_back(game_s, game_s->asset.sh_sprite.y, game_s->asset.sh_sprite.x
			- 1);
	}
}
