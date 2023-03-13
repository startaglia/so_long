/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tile_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:39 by startagl          #+#    #+#             */
/*   Updated: 2023/03/10 14:29:45 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_r_sprite_frame0(t_game *game_s, int i, int j)
{
	game_s->window.sprite_img[0] = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/zombie_frame_1_r.xpm",
			&game_s->asset.sprite.height,
			&game_s->asset.sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.sprite_img[0],
		j * game_s->asset.sprite.width,
		i * game_s->asset.sprite.height);
}

void	put_l_sprite_frame0(t_game *game_s, int i, int j)
{
	game_s->window.sprite_img[2] = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/zombie_frame_1_l.xpm",
			&game_s->asset.sprite.height,
			&game_s->asset.sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.sprite_img[2],
		j * game_s->asset.sprite.width,
		i * game_s->asset.sprite.height);
}

void	put_wall(t_game *game_s, int i, int j)
{
	game_s->window.wall_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/tiles/wall.xpm",
			&game_s->asset.wall.height,
			&game_s->asset.wall.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.wall_img,
		j * game_s->asset.wall.width,
		i * game_s->asset.wall.height);
}

void	put_back(t_game *game_s, int i, int j)
{
	game_s->window.back_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/tiles/floor_tile.xpm",
			&game_s->asset.back.height,
			&game_s->asset.back.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.back_img,
		j * game_s->asset.back.width,
		i * game_s->asset.back.height);
}

void	put_tile_ex(t_game *game_s, int i, int j)
{
	game_s->window.exit_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/tiles/grave.xpm",
			&game_s->asset.exit.height,
			&game_s->asset.exit.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.exit_img,
		j * game_s->asset.exit.width,
		i * game_s->asset.exit.height);
}
