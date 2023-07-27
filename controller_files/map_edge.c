/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:50:50 by startagl          #+#    #+#             */
/*   Updated: 2023/03/07 16:41:28 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rows(t_game *game_struct)
{
	int	i;

	i = -1;
	while (++i < game_struct->map.cols)
	{
		if (game_struct->map.map[0][i] != '1')
		{
			ft_free_mem(game_struct);
			ft_printf("\nINVALID MAP IN FIRST ROW");
			ft_printf("\nError\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < game_struct->map.cols)
	{
		if (game_struct->map.map[game_struct->map.rows - 1][i] != '1')
		{
			ft_free_mem(game_struct);
			ft_printf("\nINVALID MAP IN LAST ROW");
			ft_printf("\nError\n");
			exit(0);
		}
	}
}

void	check_cols(t_game *game_struct)
{
	int	i;

	i = -1;
	while (++i < game_struct->map.rows)
	{
		if (game_struct->map.map[i][0] != '1')
		{
			ft_free_mem(game_struct);
			ft_printf("\nINVALID MAP IN FIRST COL");
			ft_printf("\nError\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < game_struct->map.rows)
	{
		if (game_struct->map.map[i][game_struct->map.cols - 1] != '1')
		{
			ft_free_mem(game_struct);
			ft_printf("\nINVALID MAP IN LAST COL");
			ft_printf("\nError\n");
			exit(0);
		}
	}
}

/* CONTROLLA SE LA MAPPA HA I BORDI CORRETTI */
void	check_game_edge(t_game *game_struct)
{
	check_rows(game_struct);
	check_cols(game_struct);
}
