/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:09:41 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/28 15:47:15 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//To rotate the vector

//x_new = x * cos(theta) - y * sin(theta)
//y_new = x * sin(theta) + y * cos(theta)

void player_rotate_right(void)
{
    double old_direction_x;
    double old_plane_x;

    // Store the original direction_x and plane_x values for later use.
    old_direction_x = data()->player.direction_x;
    old_plane_x = data()->player.plane_x;

    // Update the direction_x component based on a clockwise rotation.
    data()->player.direction_x = data()->player.direction_x * cos(data()->player.rotate_speed) \
        - data()->player.direction_y * sin(data()->player.rotate_speed);

    // Update the direction_y component based on a clockwise rotation.
    data()->player.direction_y = old_direction_x * sin(data()->player.rotate_speed) \
        + data()->player.direction_y * cos(data()->player.rotate_speed);

    // Update the plane_x component based on a clockwise rotation.
    data()->player.plane_x = data()->player.plane_x * cos(data()->player.rotate_speed) \
        - data()->player.plane_y * sin(data()->player.rotate_speed);

    // Update the plane_y component based on a clockwise rotation.
    data()->player.plane_y = old_plane_x * sin(data()->player.rotate_speed) \
        + data()->player.plane_y * cos(data()->player.rotate_speed);
}

void player_rotate_left(void)
{
    double old_direction_x;
    double old_plane_x;

    // Store the current direction_x value in old_direction_x
    old_direction_x = data()->player.direction_x;
    old_plane_x = data()->player.plane_x;

    // Update direction_x using a counterclockwise rotation matrix
    data()->player.direction_x = data()->player.direction_x * cos(-data()->player.rotate_speed) \
        - data()->player.direction_y * sin(-data()->player.rotate_speed);

    // Update direction_y using a counterclockwise rotation matrix
    data()->player.direction_y = old_direction_x * sin(-data()->player.rotate_speed) \
        + data()->player.direction_y * cos(-data()->player.rotate_speed);

    // Store the current plane_x value in old_plane_x

    // Update plane_x using a counterclockwise rotation matrix
    data()->player.plane_x = data()->player.plane_x * cos(-data()->player.rotate_speed) \
        - data()->player.plane_y * sin(-data()->player.rotate_speed);

    // Update plane_y using a counterclockwise rotation matrix
    data()->player.plane_y = old_plane_x * sin(-data()->player.rotate_speed) \
        + data()->player.plane_y * cos(-data()->player.rotate_speed);
}

