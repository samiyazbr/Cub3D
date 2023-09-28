/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:57:44 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/27 18:46:26 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_movement(void)
{
	if (data()->key.W == 1)
		player_move_forward();
	if (data()->key.S == 1)
		player_move_backwards();
	if (data()->key.A == 1)
		player_move_left();
	if (data()->key.D == 1)
		player_move_right();
	//if (data()->key.left_key == 1)
		//player_rotate_left();
	//if (data()->key.right_key == 1)
		//player_rotate_right();
}

void player_move_forward(void)
{
    int y; //vertical coordinate
    int x; //horizontal coordinate

    // Convert the player's current Y-coordinate to an integer.
    y = (int)data()->player.position_y;

    // Calculate the potential new X-coordinate after moving forward.
    // data()->player.direction_x * data()->player.move_speed is 0 because direction_x is 0
    x = (int)(data()->player.position_x + data()->player.direction_x * data()->player.move_speed);

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's X-coordinate with the new position.
        // Here direction of x is 0 so x coordinate of the player will not change.
        data()->player.position_x += data()->player.direction_x * data()->player.move_speed;
    }

    // Calculate the potential new Y-coordinate after moving forward.
    y = (int)(data()->player.position_y + data()->player.direction_y * data()->player.move_speed);

    // Convert the player's current X-coordinate to an integer.
    x = (int)data()->player.position_x;

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's Y-coordinate with the new position.
        // value of Y decreases while moving forward because this is how we defined our coordinates(direction_y is -1)
        data()->player.position_y += data()->player.direction_y * data()->player.move_speed;
    }
}

void player_move_backwards(void)
{
    int y; //vertical coordinate
    int x; //horizontal coordinate

    // Convert the player's current Y-coordinate to an integer.
    y = (int)data()->player.position_y;

    // Calculate the potential new X-coordinate after moving backward.
    x = (int)(data()->player.position_x - data()->player.direction_x * data()->player.move_speed);

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's X-coordinate with the new position.
        // Here direction of x is 0 so x coordinate of the player will not change.
        data()->player.position_x -= data()->player.direction_x * data()->player.move_speed;
    }

    // Calculate the potential new Y-coordinate after moving backward.
    y = (int)(data()->player.position_y - data()->player.direction_y * data()->player.move_speed);

    // Convert the player's current X-coordinate to an integer.
    x = (int)data()->player.position_x;

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's Y-coordinate with the new position.
        // value of Y increases while moving backward because this is how we defined our coordinates(direction_y is 1)
        data()->player.position_y -= data()->player.direction_y * data()->player.move_speed;
    }
}

void player_move_left(void)
{
    int y; //vertical coordinate
    int x; //horizontal coordinate

    // Convert the player's current Y-coordinate to an integer.
    y = (int)data()->player.position_y;

    // Calculate the potential new X-coordinate after moving to the left.
    x = (int)(data()->player.position_x + data()->player.direction_y * data()->player.move_speed);

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's X-coordinate with the new position.
        // value of X increases while moving left because this is how we defined our coordinates(direction_x is 1)
        data()->player.position_x += data()->player.direction_y * data()->player.move_speed;
    }

    // Calculate the potential new Y-coordinate after moving to the left.
    y = (int)(data()->player.position_y - data()->player.direction_x * data()->player.move_speed);

    // Convert the player's current X-coordinate to an integer.
    x = (int)data()->player.position_x;

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's Y-coordinate with the new position.
        // Here direction of y is 0 so y coordinate of the player will not change.
        data()->player.position_y -= data()->player.direction_x * data()->player.move_speed;
    }
}

void player_move_right(void)
{
    int y; //vertical coordinate
    int x; //horizontal coordinate

    // Convert the player's current Y-coordinate to an integer.
    y = (int)data()->player.position_y;

    // Calculate the potential new X-coordinate after moving to the right.
    x = (int)(data()->player.position_x - data()->player.direction_y * data()->player.move_speed);

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's X-coordinate with the new position.
         // value of X decreases while moving right because this is how we defined our coordinates(direction_x is -1)
        data()->player.position_x -= data()->player.direction_y * data()->player.move_speed;
    }

    // Calculate the potential new Y-coordinate after moving to the right.
    y = (int)(data()->player.position_y + data()->player.direction_x * data()->player.move_speed);

    // Convert the player's current X-coordinate to an integer.
    x = (int)data()->player.position_x;

    // Check if the new position in the map is not a wall ('1').
    if (data()->map[y][x] != '1')
    {
        // Update the player's Y-coordinate with the new position.
        // Here direction of y is 0 so y coordinate of the player will not change.
        data()->player.position_y += data()->player.direction_x * data()->player.move_speed;
    }
}

