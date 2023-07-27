/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:34 by startagl          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:35 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game_s)
{
	usleep(1000);
	ft_printf("YOU LOOOSE\n");
	free(game_s->asset.sprite.steps_str);
	exit(0);
}

int	check_wall(t_game *game_s)
{
	if ((game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == '1')
		|| (game_s->map.map[game_s->asset.sprite.p_y]
			[game_s->asset.sprite.p_x] == 'E'))
		return (1);
	return (0);
}

void	get_coin(t_game *game_s)
{
	if (game_s->map.map[game_s->asset.sprite.p_y]
		[game_s->asset.sprite.p_x] == 'C')
	{
		if ((game_s->map.map[game_s->asset.sprite.p_y]
				[game_s->asset.sprite.p_x + 1] == 'L')
			|| (game_s->map.map[game_s->asset.sprite.p_y]
				[game_s->asset.sprite.p_x - 1] == 'L')
			|| (game_s->map.map[game_s->asset.sprite.p_y]
				[game_s->asset.sprite.p_x + 1] == 'R')
			|| (game_s->map.map[game_s->asset.sprite.p_y]
				[game_s->asset.sprite.p_x - 1] == 'R'))
		{
			usleep(1000);
			ft_printf("POISONED COIN, YOU LOSE\n");
			exit(0);
		}
		game_s->asset.clct.coint_c--;
		ft_printf("REMAINING COIN: %d\n", game_s->asset.clct.coint_c);
	}
}

void	check_side(int key, t_game *game_s)
{
	if (game_s->asset.sprite.side)
		put_l_sprite_frame0(game_s, game_s->asset.sprite.p_y,
			game_s->asset.sprite.p_x);
	else if (!game_s->asset.sprite.side)
		put_r_sprite_frame0(game_s, game_s->asset.sprite.p_y,
			game_s->asset.sprite.p_x);
	modify_val(game_s, key);
}

int	move_sprite(int key, t_game *game_s)
{
	if (key == 53)
		destroy_win(game_s);
	else if (key == 13)
		move_up(key, game_s);
	else if (key == 0)
		move_left(key, game_s);
	else if (key == 1)
		move_down(key, game_s);
	else if (key == 2)
		move_right(key, game_s);
	return (0);
}
