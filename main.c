/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:25:47 by startagl          #+#    #+#             */
/*   Updated: 2023/04/25 12:43:22 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//? MAIN:
//?	- CREA MAPPA
//? - CALL FUNCTIONS CHE CONTROLLANO CHE LA MAPPA SIA VALIDA
//? SHAPE CHECK
//? EDGE CHECK
//? VALUES CHECK
//?	- LANCIA FINESTRA
//?	- METTE I TILE NELLA FINESTRA
//?	- GESTIRE GLI EVENTI
//?	- CHIUDE LA FINESTRA

//!	- TO FIX

//! - IL PLAYER NON MUORE SE VA ATTACCATO AL POLICE NELLA DIREZIONE DELLO SHOOT;

t_game	*initialize_sprites_v(void)
{
	t_game	*game_s;

	game_s = malloc(sizeof(t_game));
	game_s->asset.sprite.height = 64;
	game_s->asset.sprite.width = 64;
	game_s->asset.sprite.side = 0;
	game_s->asset.sprite.step_counter = 0;
	game_s->asset.w_sprite.height = 64;
	game_s->asset.w_sprite.width = 64;
	game_s->asset.lp_sprite.height = 64;
	game_s->asset.lp_sprite.width = 64;
	game_s->asset.lp_sprite.shoot_switch = 0;
	game_s->asset.lp_sprite.first_shoot_on_side = 0;
	game_s->asset.lp_sprite.first_shoot = 0;
	game_s->asset.lp_sprite.back = 0;
	game_s->asset.lp_sprite.stuck = 0;
	game_s->asset.lp_sprite.stuck_w = 0;
	game_s->asset.sh_sprite.arrived = 0;
	game_s->asset.w_sprite.move_up = 1;
	return (game_s);
}

t_game	*initialize_tiles_v(t_game *game_s)
{
	game_s->count_c = 0;
	game_s->count_p = 0;
	game_s->count_e = 0;
	game_s->count_w_en = 0;
	game_s->count_lp_en = 0;
	game_s->map.cols = 0;
	game_s->map.rows = 0;
	game_s->asset.wall.width = 64;
	game_s->asset.wall.height = 64;
	game_s->asset.back.height = 64;
	game_s->asset.clct.coint_c = 0;
	// game_s->asset.exit.x = 0;
	// game_s->asset.exit.y = 0;
	game_s->start_flag = 0;
	gettimeofday(&(game_s->curr_tm), NULL);
	return (game_s);
}

int	get_rows(t_game *game_s, char *line, int fd_open)
{
	while (line)
	{
		game_s->map.rows++;
		free(line);
		line = get_next_line(fd_open);
	}
	free(line);
	close(fd_open);
	return (game_s->map.rows);
}

// * CONVERT MAP FROM .BER FILE */
void	convert_map(t_game *game_s, char *map_name)
{
	int		fd_open;
	int		i;
	char	*line;

	i = 0;
	ft_printf("av: %s\n", map_name);
	fd_open = open(map_name, O_RDONLY);
	line = get_next_line(fd_open);
	game_s->map.rows = get_rows(game_s, line, fd_open);
	game_s->map.map = (char **)malloc(game_s->map.rows * sizeof(char *));
	fd_open = open(map_name, O_RDONLY);
	if ((fd_open < 0) || (!game_s->map.map))
		return ;
	line = get_next_line(fd_open);
	while (line)
	{
		game_s->map.map[i] = ft_strdup(line);
		if (game_s->map.map[i][ft_strlen(game_s->map.map[i]) - 1] == '\n')
			game_s->map.map[i][ft_strlen(game_s->map.map[i]) - 1] = '\0';
		free(line);
		line = get_next_line(fd_open);
		i++;
	}
	free(line);
	close(fd_open);
}

int	main(int ac, char **av)
{
	t_game	*game_s;

	if (ac == 2)
	{
		game_s = initialize_sprites_v();
		game_s = initialize_tiles_v(game_s);
		check_format_map(av[1]);
		convert_map(game_s, av[1]);
		game_s->map.cols = ft_strlen(game_s->map.map[0]);
		check_shape(game_s);
		check_game_edge(game_s);
		check_values(game_s);
		check_necessary_values(game_s);
		load_win(game_s);
		preload_map(game_s);
		load_map(game_s);
		game_s->start_flag = 1;
		mlx_key_hook(game_s->window.win, move_sprite, game_s);
		start_animation(game_s);
		mlx_hook(game_s->window.win, 17, 0, destroy_win, (void *)game_s);
		mlx_loop(game_s->window.mlx);
	}
	else
		ft_printf("Too few arguments\n");
	return (0);
}
