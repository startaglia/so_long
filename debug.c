/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:42:29 by startagl          #+#    #+#             */
/*   Updated: 2023/03/08 08:43:59 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//* Debug function's
void	print_matrix(int cols, int rows, char **map)
{
	int	i;
	int	j;

	(void) cols;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf(" %c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
