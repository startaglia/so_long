/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:29:33 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 16:48:08 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*set_flag(t_game *game_s, int *flag)
{
	game_s->asset.lp_sprite.first_shoot_on_side = 1;
	if (game_s->asset.lp_sprite.shoot_switch == 0)
		*flag = 1;
	else
		*flag = 0;
	return (flag);
}

void	turn_policeman_to_left(t_game *game_s)
{
	game_s->asset.lp_sprite.first_shoot_on_side = 0;
	put_back(game_s, game_s->asset.sh_sprite.y,
		game_s->asset.sh_sprite.x);
	if (game_s->asset.lp_sprite.shoot_switch == 1)
	{
		game_s->asset.sh_sprite.y = game_s->asset.lp_sprite.y;
		game_s->asset.sh_sprite.x = game_s->asset.lp_sprite.x;
	}
	game_s->asset.lp_sprite.shoot_switch = 0;
	put_left_police(game_s, game_s->asset.lp_sprite.y,
		game_s->asset.lp_sprite.x);
	shoot_left(game_s);
}

void	set_stucked(t_game *game_s)
{
	if (game_s->asset.lp_sprite.x < game_s->asset.sprite.p_x)
	{
		put_right_police(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x);
	}
	else
	{
		put_left_police(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x);
	}
	return ;
}

void	put_police_man(t_game *game_s)
{
	int	flag;

	flag = 0;
	if (game_s->asset.lp_sprite.stuck)
		set_stucked(game_s);
	else
	{
		if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x)
			set_flag(game_s, &flag);
		else if (game_s->asset.lp_sprite.x < game_s->asset.sprite.p_x)
			turn_policeman_to_right(game_s);
		else if (game_s->asset.lp_sprite.x > game_s->asset.sprite.p_x)
			turn_policeman_to_left(game_s);
		if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x)
		{
			if (flag == 0)
				shoot_right(game_s);
			else if (flag == 1)
				shoot_left(game_s);
		}
		game_s->asset.lp_sprite.first_shoot = 1;
	}
}

int	animations(t_game *game_s)
{
	if (ft_gettimestamp(game_s) >= 250)
	{
		if (game_s->count_w_en > 0)
		{
			chainsaw_move_up(game_s);
			if (game_s->asset.w_sprite.move_up == 0)
				chainsaw_move_down(game_s);
		}
		if (game_s->count_lp_en > 0)
			put_police_man(game_s);
	}
	return (1);
}
