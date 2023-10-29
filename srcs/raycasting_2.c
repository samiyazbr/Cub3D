/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:22:47 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/29 16:16:23 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_y_movement_and_y_intersection_distance(void)
{
	if (data()->player.raydirection_y < 0)
	{
		data()->player.y_movement = -1;
		data()->player.y_intersection_distance = (data()->player.position_y \
		- data()->player.map_y) * data()->player.delta_distance_y;
	}
	else
	{
		data()->player.y_movement = 1;
		data()->player.y_intersection_distance = (data()->player.map_y + 1.0 \
		- data()->player.position_y) * data()->player.delta_distance_y;
	}
}

void	dda(void)
{
	while (data()->player.hit == 0)
	{
		if (data()->player.x_intersection_distance < \
		data()->player.y_intersection_distance)
		{
			data()->player.x_intersection_distance
			+= data()->player.delta_distance_x;
			data()->player.map_x += data()->player.x_movement;
			data()->player.side = 0;
		}
		else
		{
			data()->player.y_intersection_distance
			+= data()->player.delta_distance_y;
			data()->player.map_y += data()->player.y_movement;
			data()->player.side = 1;
		}
		if (data()->map[data()->player.map_y][data()->player.map_x] == '1')
		{
			data()->player.hit = 1;
			set_texture();
		}
	}
}

void	set_texture(void)
{
	if (data()->player.side == 0)
	{
		if (data()->player.map_x > data()->player.position_x)
			data()->player.texture_id = 1;
		else
			data()->player.texture_id = 3;
	}
	else
	{
		if (data()->player.map_y > data()->player.position_y)
			data()->player.texture_id = 2;
		else
			data()->player.texture_id = 0;
	}
}

void	calculateperspectivewalldistance(void)
{
	if (data()->player.side == 0)
	{
		data()->player.perspective_wall_distance = \
		data()->player.x_intersection_distance \
		- data()->player.delta_distance_x;
	}
	else
	{
		data()->player.perspective_wall_distance = \
		data()->player.y_intersection_distance \
		- data()->player.delta_distance_y;
	}
}
