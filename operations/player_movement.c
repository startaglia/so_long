/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:53:30 by startagl          #+#    #+#             */
/*   Updated: 2023/03/11 17:18:37 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(int key, t_game *game_s)
{
	game_s->asset.sprite.p_y--;
	game_s->asset.sprite.step_counter++;
	free(game_s->asset.sprite.steps_str);
	game_s->asset.sprite.steps_str = ft_itoa(game_s->asset.sprite.step_counter);
	if (!check_wall(game_s))
	{
		get_coin(game_s);
		check_side(key, game_s);
	}
	else if (game_s->asset.clct.coint_c == 0
		&& game_s->map.map[game_s->asset.sprite.p_y]
		[game_s->asset.sprite.p_x] == 'E')
	{
		ft_printf("YOU WIN!\n");
		exit(0);
	}
	else
	{
		game_s->asset.sprite.p_y++;
		return ;
	}
}

void	move_down(int key, t_game *game_s)
{
	game_s->asset.sprite.p_y++;
	game_s->asset.sprite.step_counter++;
	free(game_s->asset.sprite.steps_str);
	game_s->asset.sprite.steps_str = ft_itoa(game_s->asset.sprite.step_counter);
	if (!check_wall(game_s))
	{
		get_coin(game_s);
		check_side(key, game_s);
	}
	else if (game_s->asset.clct.coint_c == 0
		&& game_s->map.map[game_s->asset.sprite.p_y]
		[game_s->asset.sprite.p_x] == 'E')
	{
		ft_printf("YOU WIN!\n");
		exit(0);
	}
	else
	{
		game_s->asset.sprite.p_y--;
		return ;
	}
}

void	move_left(int key, t_game *game_s)
{
	game_s->asset.sprite.side = 1;
	game_s->asset.sprite.p_x--;
	game_s->asset.sprite.step_counter++;
	free(game_s->asset.sprite.steps_str);
	game_s->asset.sprite.steps_str = ft_itoa(game_s->asset.sprite.step_counter);
	if (!check_wall(game_s))
	{
		get_coin(game_s);
		check_side(key, game_s);
	}
	else if (game_s->asset.clct.coint_c == 0
		&& game_s->map.map[game_s->asset.sprite.p_y]
		[game_s->asset.sprite.p_x] == 'E')
	{
		ft_printf("YOU WIN!\n");
		exit(0);
	}
	else
	{
		game_s->asset.sprite.p_x++;
		return ;
	}
}

void	move_right(int key, t_game *game_s)
{
	game_s->asset.sprite.side = 0;
	game_s->asset.sprite.p_x++;
	game_s->asset.sprite.step_counter++;
	free(game_s->asset.sprite.steps_str);
	game_s->asset.sprite.steps_str = ft_itoa(game_s->asset.sprite.step_counter);
	if (!check_wall(game_s))
	{
		get_coin(game_s);
		check_side(key, game_s);
	}
	else if (game_s->asset.clct.coint_c == 0
		&& game_s->map.map[game_s->asset.sprite.p_y]
		[game_s->asset.sprite.p_x] == 'E')
	{
		ft_printf("YOU WIN!\n");
		exit(0);
	}
	else
	{
		game_s->asset.sprite.p_x--;
		return ;
	}
}
