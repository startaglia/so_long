/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_to_put_enemy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:52:30 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 17:16:42 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_w_on_col(t_game *game_s, int col_num)
{
	int	i;

	i = 0;
	while (i < game_s->map.rows)
	{
		if (game_s->map.map[i][col_num] == 'W')
		{
			ft_printf("Chainsaw and police are too close\n");
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
}

void	put_correct_police_man(t_game *game_s, int side, int shoot_switch)
{
	game_s->asset.lp_sprite.shoot_switch = shoot_switch;
	if (!side)
		put_left_police(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x);
	else
		put_right_police(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x);
}

void	police_man_control(t_game *game_s)
{
	if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
		&& (whats_on_right(game_s) && whats_on_left(game_s)))
		put_correct_police_man(game_s, 0, 0);
	else if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
		&& (!whats_on_right(game_s) && !whats_on_left(game_s)))
		put_correct_police_man(game_s, 1, 1);
	else if (game_s->asset.lp_sprite.x < game_s->asset.sprite.p_x)
	{
		put_right_police(game_s, game_s->asset.lp_sprite.y,
			game_s->asset.lp_sprite.x);
	}
	else if (game_s->asset.lp_sprite.x > game_s->asset.sprite.p_x)
		put_correct_police_man(game_s, 0, 1);
	else if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
		&& whats_on_left(game_s))
		put_correct_police_man(game_s, 1, 0);
	else if (game_s->asset.lp_sprite.x == game_s->asset.sprite.p_x
		&& whats_on_right(game_s))
		put_correct_police_man(game_s, 0, 0);
}
