/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directional_vectors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:16:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/05 13:57:27 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//this function is not being called
static void	set_values(double direction_x, double direction_y,
						double plane_x, double plane_y)
{
	// direction and plane value is 0 why?
	data()->player.direction_x = direction_x;
	// printf("direction_x: %f\n",data()->player.direction_x);
	data()->player.direction_y = direction_y;
	// printf("direction_y: %f\n",data()->player.direction_y);
	data()->player.plane_x = plane_x;
	// printf("plane_x: %f\n",data()->player.plane_x);
	data()->player.plane_y = plane_y;
	// printf("plane_y: %f\n",data()->player.plane_y);
}

// this function is not being called because we are not using valid_map at the moment
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
