/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:09:41 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/29 15:41:09 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// To rotate the vector

// x_new = x * cos(theta) - y * sin(theta)
// y_new = x * sin(theta) + y * cos(theta)

void	player_rotate_right(void)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = data()->player.direction_x;
	old_plane_x = data()->player.plane_x;
	data()->player.direction_x = data()->player.direction_x
	* cos(data()->player.rotate_speed) - data()->player.direction_y
	* sin(data()->player.rotate_speed);
	data()->player.direction_y = old_direction_x
	* sin(data()->player.rotate_speed) + data()->player.direction_y
	* cos(data()->player.rotate_speed);
	data()->player.plane_x = data()->player.plane_x
	* cos(data()->player.rotate_speed) - data()->player.plane_y
	* sin(data()->player.rotate_speed);
	data()->player.plane_y = old_plane_x * sin(data()->player.rotate_speed)
	+ data()->player.plane_y * cos(data()->player.rotate_speed);
}

void	player_rotate_left(void)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = data()->player.direction_x;
	old_plane_x = data()->player.plane_x;
	data()->player.direction_x = data()->player.direction_x
	* cos(-data()->player.rotate_speed) - data()->player.direction_y
	* sin(-data()->player.rotate_speed);
	data()->player.direction_y = old_direction_x
	* sin(-data()->player.rotate_speed) + data()->player.direction_y
	* cos(-data()->player.rotate_speed);
	data()->player.plane_x = data()->player.plane_x
	* cos(-data()->player.rotate_speed) - data()->player.plane_y
	* sin(-data()->player.rotate_speed);
	data()->player.plane_y = old_plane_x * sin(-data()->player.rotate_speed)
	+ data()->player.plane_y * cos(-data()->player.rotate_speed);
}
