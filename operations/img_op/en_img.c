/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:33:12 by startagl          #+#    #+#             */
/*   Updated: 2023/03/10 13:46:53 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_chsaw_en(t_game *game_s, int i, int j)
{
	game_s->window.w_sprite_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/chainsaw_man_l.xpm",
			&game_s->asset.w_sprite.height,
			&game_s->asset.w_sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.w_sprite_img,
		j * game_s->asset.w_sprite.width,
		i * game_s->asset.w_sprite.height);
}

void	put_left_police(t_game *game_s, int i, int j)
{
	game_s->window.lp_sprite_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/police_man_l.xpm",
			&game_s->asset.lp_sprite.height,
			&game_s->asset.lp_sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.lp_sprite_img,
		j * game_s->asset.lp_sprite.width,
		i * game_s->asset.lp_sprite.height);
}

void	put_right_police(t_game *game_s, int i, int j)
{
	game_s->window.lp_sprite_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/police_man_r.xpm",
			&game_s->asset.lp_sprite.height,
			&game_s->asset.lp_sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.lp_sprite_img,
		j * game_s->asset.lp_sprite.width,
		i * game_s->asset.lp_sprite.height);
}

void	put_shoot_sprite(t_game *game_s, int i, int j)
{
	game_s->window.sh_sprite_img = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/tiles/shoot.xpm",
			&game_s->asset.sh_sprite.height,
			&game_s->asset.sh_sprite.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.sh_sprite_img,
		j * game_s->asset.sh_sprite.width,
		i * game_s->asset.sh_sprite.height);
}

void	put_tile_c(t_game *game_s, int i, int j)
{
	game_s->window.clct_img[0] = mlx_xpm_file_to_image(game_s->window.mlx,
			"./assets/sprites/collect_3.xpm",
			&game_s->asset.clct.height,
			&game_s->asset.clct.width);
	mlx_put_image_to_window(game_s->window.mlx, game_s->window.win,
		game_s->window.clct_img[0],
		j * game_s->asset.clct.width,
		i * game_s->asset.clct.height);
}
