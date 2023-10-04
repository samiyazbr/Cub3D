/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:24:55 by samiyazubai       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/04 17:54:33 by samiyazubai      ###   ########.fr       */
=======
/*   Updated: 2023/10/03 19:57:11 by samiyazubai      ###   ########.fr       */
>>>>>>> 963d201b89ff22298794caa2d01e50d7351def73
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// This function calculates the position and direction of a ray based on the given 'x' value.
void find_rayposition_and_raydirection(int x)
{
    // Calculate the normalized camera_x coordinate based on the screen width.
    // This value will range from -1 (leftmost) to 1 (rightmost) on the screen.
    data()->player.camera_x = 2 * x / (double) SCREEN_WIDTH - 1;

    // Calculate the x component of the ray direction by adding the camera's direction_x
    // to the camera's plane_x, scaled by the camera_x coordinate.
    data()->player.raydirection_x = data()->player.direction_x + \
                            data()->player.plane_x * data()->player.camera_x;

    // Calculate the y component of the ray direction by adding the camera's direction_y
    // to the camera's plane_y, scaled by the camera_x coordinate.
    data()->player.raydirection_y = data()->player.direction_y + \
                            data()->player.plane_y * data()->player.camera_x;
}

// This function sets the position of a wall in the game world and initializes the 'hit' variable.
void set_wall_position(void)
{
    // Convert the double 'position_x' to an integer to determine the box's map grid X coordinate.
    data()->player.map_x = (int) data()->player.position_x;

    // Convert the double 'position_y' to an integer to determine the box's map grid Y coordinate.
    data()->player.map_y = (int) data()->player.position_y;

    // Initialize the 'hit' variable to 0, indicating that the box has not been hit.
    data()->player.hit = 0;
}

// This function calculates the delta distance in the x and y directions for the raycasting algorithm.
void set_delta_distance(void)
{
    // Check if the ray's x-direction component is zero.
    if (data()->player.raydirection_x == 0)
    {
        // If the ray is parallel to the y-axis, set delta_distance_x to a very large value.
        data()->player.delta_distance_x = 1e20;
    }
    else
    {
        // Calculate delta_distance_x as the absolute value of 1 divided by the ray's x-direction component.
		//fabs() gets the absolute value
        data()->player.delta_distance_x = fabs(1 / data()->player.raydirection_x);
    }

    // Check if the ray's y-direction component is zero.
    if (data()->player.raydirection_y == 0)
    {
        // If the ray is parallel to the x-axis, set delta_distance_y to a very large value.
        data()->player.delta_distance_y = 1e20;
    }
    else
    {
        // Calculate delta_distance_y as the absolute value of 1 divided by the ray's y-direction component.
        data()->player.delta_distance_y = fabs(1 / data()->player.raydirection_y);
    }
}

<<<<<<< HEAD
void find_x_movement_and_x_intersection_distance(void)
{
    // Check if the ray direction in the x-axis is negative
    if (data()->player.raydirection_x < 0)
    {
        // If it's negative, set x_movement to -1 (moving to the left)
        data()->player.x_movement = -1;
        
        // Calculate the x_intersection_distance using the formula:
        // (position_x - map_x) * delta_distance_x
        data()->player.x_intersection_distance = (data()->player.position_x
                                                - data()->player.map_x)
                                                * data()->player.delta_distance_x;
    }
    else
    {
        // If the ray direction in the x-axis is non-negative, set x_movement to 1 (moving to the right)
        data()->player.x_movement = 1;
        
        // Calculate the x_intersection_distance using the formula:
        // (map_x + 1.0 - position_x) * delta_distance_x
        data()->player.x_intersection_distance = (data()->player.map_x + 1.0
                                                - data()->player.position_x)
                                                * data()->player.delta_distance_x;
    }
}

=======
>>>>>>> 963d201b89ff22298794caa2d01e50d7351def73
void    raycasting(void)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		find_rayposition_and_raydirection(x);
		set_wall_position();
<<<<<<< HEAD
		set_delta_distance();
		find_x_movement_and_x_intersection_distance();
		find_y_movement_and_y_intersection_distance();
		dda();
=======
		set_delta_distance();	
>>>>>>> 963d201b89ff22298794caa2d01e50d7351def73
        x++;
    }
}