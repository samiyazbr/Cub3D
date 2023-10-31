/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:24:55 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/31 15:32:22 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_rayposition_and_raydirection(int x)
{
	data()->player.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	data()->player.raydirection_x = data()->player.direction_x
	+ data()->player.plane_x * data()->player.camera_x;
	data()->player.raydirection_y = data()->player.direction_y
	+ data()->player.plane_y * data()->player.camera_x;
}

void	set_wall_position(void)
{
	data()->player.map_x = (int)data()->player.position_x;
	data()->player.map_y = (int)data()->player.position_y;
	data()->player.hit = 0;
}

void	set_delta_distance(void)
{
	if (data()->player.raydirection_x == 0)
	{
		data()->player.delta_distance_x = 1e20;
	}
	else
	{
		data()->player.delta_distance_x = fabs(1
			/ data()->player.raydirection_x);
	}
	if (data()->player.raydirection_y == 0)
	{
		data()->player.delta_distance_y = 1e20;
	}
	else
	{
		data()->player.delta_distance_y = fabs(1
			/ data()->player.raydirection_y);
	}
}

void	find_x_movement_and_x_intersection_distance(void)
{
	if (data()->player.raydirection_x < 0)
	{
		data()->player.x_movement = -1;
		data()->player.x_intersection_distance = (data()->player.position_x
			- data()->player.map_x) * data()->player.delta_distance_x;
	}
	else
	{
		data()->player.x_movement = 1;
		data()->player.x_intersection_distance = (data()->player.map_x + 1.0
			- data()->player.position_x) * data()->player.delta_distance_x;
	}
}

void	raycasting(void)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		find_rayposition_and_raydirection(x);
		set_wall_position();
		set_delta_distance();
		find_x_movement_and_x_intersection_distance();
		find_y_movement_and_y_intersection_distance();
		dda();
		calculateperspectivewalldistance();
		calculate_vertical_line_height();
		calculateverticaldrawingbounds();
		calculatetexturecoordinatex();
		draw_vertical_texture_stripe(x);
		x++;
	}
}
