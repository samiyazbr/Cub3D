/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directional_vectors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:16:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/29 13:10:21 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_values(double direction_x, double direction_y,
						double plane_x, double plane_y)
{
	data()->player.direction_x = direction_x;
	data()->player.direction_y = direction_y;
	data()->player.plane_x = plane_x;
	data()->player.plane_y = plane_y;
}

void	init_directional_vectors(int x, int y)
{
	data()->player.position_x = x + 0.5;
	data()->player.position_y = y + 0.5;
	if (data()->map[y][x] == 'N')
		set_values(0, -1, 0.66, 0);
	else if (data()->map[y][x] == 'S')
		set_values(0, 1, -0.66, 0);
	else if (data()->map[y][x] == 'E')
		set_values(1, 0, 0, 0.66);
	else if (data()->map[y][x] == 'W')
		set_values(-1, 0, 0, -0.66);
}
