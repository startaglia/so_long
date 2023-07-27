/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:26:15 by startagl          #+#    #+#             */
/*   Updated: 2023/03/13 17:53:15 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_values(t_game *game_s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game_s->map.rows)
	{
		j = -1;
		while (++j < game_s->map.cols)
		{
			if (game_s->map.map[i][j] == 'P')
				game_s->count_p++;
			else if (game_s->map.map[i][j] == 'C')
				game_s->count_c++;
			else if (game_s->map.map[i][j] == 'E')
				game_s->count_e++;
			else if (game_s->map.map[i][j] == 'W')
				game_s->count_w_en++;
			else if (game_s->map.map[i][j] == 'L')
				game_s->count_lp_en++;
		}
	}
}

void	check_necessary_values(t_game *game_s)
{
	int	i;

	count_values(game_s);
	if ((game_s->count_p++ != 1) || (game_s->count_e++ != 1)
		|| (game_s->count_c < 1))
	{
		ft_printf("You need only one p, one exit and almost one collectable\n");
		ft_printf("Error\n");
		ft_free_mem(game_s);
		exit(0);
	}	
	if (game_s->count_rp_en > 0 && game_s->count_lp_en > 0)
		i = 1;
	if (!(game_s->count_w_en < 2 && game_s->count_lp_en < 2))
	{
		ft_printf("Too many enemies\n");
		ft_printf("Error\n");
		ft_free_mem(game_s);
		exit(0);
	}
}

void	check_values(t_game *game_s)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_s->map.rows)
	{
		j = 0;
		while (j < game_s->map.cols)
		{
			if (game_s->map.map[i][j] != 'P' && game_s->map.map[i][j] != 'C'
				&& game_s->map.map[i][j] != 'E' && game_s->map.map[i][j] != '0'
				&& game_s->map.map[i][j] != '1' && game_s->map.map[i][j] != 'W'
				&& game_s->map.map[i][j] != 'L')
			{
				ft_printf ("Wrong values\n");
				ft_printf ("Error\n");
				ft_free_mem (game_s);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
