/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:16:19 by startagl          #+#    #+#             */
/*   Updated: 2023/03/13 17:36:00 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_win(t_game *game_s)
{
	game_s->window.mlx = mlx_init();
	game_s->window.heigth = game_s->map.rows * game_s->asset.wall.width;
	game_s->window.widht = game_s->map.cols * game_s->asset.wall.height;
	game_s->window.win = mlx_new_window(game_s->window.mlx,
			game_s->window.widht, game_s->window.heigth, "Oscar the zombie");
}

int	destroy_win(t_game *game_struct)
{
	mlx_destroy_image(game_struct->window.mlx, game_struct->window.wall_img);
	mlx_destroy_window(game_struct->window.mlx, game_struct->window.win);
	ft_free_mem(game_struct);
	exit(0);
}
