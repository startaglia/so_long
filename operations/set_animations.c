/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:31:39 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:39 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_shoot_cordinates(t_game *game_s, int x)
{
	game_s->asset.sh_sprite.y = game_s->asset.lp_sprite.y;
	if (!x)
		game_s->asset.sh_sprite.x = game_s->asset.lp_sprite.x - 1;
	else if (x)
		game_s->asset.sh_sprite.x = game_s->asset.lp_sprite.x + 1;
}

int	ft_gettimestamp(t_game *game_s)
{
	struct timeval	now;
	int				res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((game_s->curr_tm.tv_sec * 1000)
				+ (game_s->curr_tm.tv_usec / 1000)));
	if (res >= 250)
		game_s->curr_tm = now;
	return (res);
}

void	set_start_shoot(t_game *game_s)
{
	if (game_s->count_lp_en > 0)
	{
		if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
			&& (whats_on_right(game_s) && whats_on_left(game_s)))
			game_s->asset.lp_sprite.stuck = 1;
		if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
			&& (!whats_on_right(game_s) && !whats_on_left(game_s)))
		{
			game_s->asset.lp_sprite.shoot_switch = 1;
			game_s->asset.lp_sprite.first_shoot_on_side = 0;
			set_shoot_cordinates(game_s, 1);
		}
		else if (game_s->asset.lp_sprite.x < game_s->asset.sprite.p_x)
			set_shoot_cordinates(game_s, 1);
		else if (game_s->asset.lp_sprite.x > game_s->asset.sprite.p_x)
			set_shoot_cordinates(game_s, 0);
		else if (whats_on_left(game_s))
			set_shoot_cordinates(game_s, 1);
		else if (whats_on_right(game_s))
			set_shoot_cordinates(game_s, 0);
	}
}

void	start_animation(t_game *game_s)
{
	set_start_shoot(game_s);
	mlx_loop_hook(game_s->window.mlx, animations, (void *)game_s);
}
