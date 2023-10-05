/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:22:47 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/05 14:05:30 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void find_y_movement_and_y_intersection_distance(void)
{   
    // Check if the ray direction in the y-axis is negative
    if (data()->player.raydirection_y < 0)
    {
        // If it's negative, set y_movement to -1 (moving upwards)
        data()->player.y_movement = -1;
        
        // Calculate the y_intersection_distance using the formula:
        // (position_y - map_y) * delta_distance_y
        data()->player.y_intersection_distance = (data()->player.position_y
                                                - data()->player.map_y)
                                                * data()->player.delta_distance_y;
    }
    else
    {
        // If the ray direction in the y-axis is non-negative, set y_movement to 1 (moving downwards)
        data()->player.y_movement = 1;
        
        // Calculate the y_intersection_distance using the formula:
        // (map_y + 1.0 - position_y) * delta_distance_y
        data()->player.y_intersection_distance = (data()->player.map_y + 1.0
                                                - data()->player.position_y)
                                                * data()->player.delta_distance_y;
    }
}

void dda(void)
{
    // Continue the loop as long as there is no collision (hit == 0)
    while (data()->player.hit == 0)
    {
        // Check if the x_intersection_distance is smaller than y_intersection_distance
        if (data()->player.x_intersection_distance < data()->player.y_intersection_distance)
        {
            // Increment x_intersection_distance by delta_distance_x
            data()->player.x_intersection_distance += data()->player.delta_distance_x;
            
            // Move to the next grid cell in the x-axis (map_x) based on x_movement
            data()->player.map_x += data()->player.x_movement;
            
            // Set the "movement" variable to 0 (indicating horizontal movement)
            data()->player.side = 0;
        }
        else
        {
            // If y_intersection_distance is smaller or equal, perform similar actions in the y-axis
            data()->player.y_intersection_distance += data()->player.delta_distance_y;
            data()->player.map_y += data()->player.y_movement;
            
            // Set the "movement" variable to 1 (indicating vertical movement)
            data()->player.side = 1;
        }
        
        // Check if the current map cell contains a wall ('1')
        if (data()->map[data()->player.map_y][data()->player.map_x] == '1')
        {
            // If a wall is hit, set the "hit" variable to 1 to exit the loop
            data()->player.hit = 1;
            
            // Perform some action to handle the texture (e.g., rendering)
            set_texture();
        }
    }
}

void set_texture(void)
{
    // Check if the player's movement is horizontal (movement == 0)
    if (data()->player.side == 0)
    {
        // Check if the map_x coordinate of the intersection is greater than the player's position_x
        if (data()->player.map_x > data()->player.position_x)
            data()->player.texture_id = 1; // Set the player's texture_id to 1
        else
            data()->player.texture_id = 3; // Otherwise, set the player's texture_id to 3
    }
    else // Player's movement is vertical (movement == 1)
    {
        // Check if the map_y coordinate of the intersection is greater than the player's position_y
        if (data()->player.map_y > data()->player.position_y)
            data()->player.texture_id = 2; // Set the player's texture_id to 2
        else
            data()->player.texture_id = 0; // Otherwise, set the player's texture_id to 0
    }
}

void calculatePerspectiveWallDistance(void)
{
    // Check if the side is horizontal (side == 0)
    if (data()->player.side == 0)
    {
        // Calculate the perspective_wall_distance for a horizontal side
        // by subtracting delta_distance_x from side_distance_x
        data()->player.perspective_wall_distance = data()->player.x_intersection_distance - data()->player.delta_distance_x;
    }
    else
    {
        // Calculate the perspective_wall_distance for a vertical side
        // by subtracting delta_distance_y from side_distance_y
        data()->player.perspective_wall_distance = data()->player.y_intersection_distance - data()->player.delta_distance_y;
    }
}

void calculate_vertical_line_height(void)
{
    // Calculate the line_height by dividing SCREEN_HEIGHT by perspective_wall_distance
    data()->player.line_height = (int)(SCREEN_HEIGHT / data()->player.perspective_wall_distance);
    //printf("line_height: %d\n", data()->player.line_height);
}

void calculateVerticalDrawingBounds(void)
{
    // Calculate the initial draw_start based on line_height and SCREEN_HEIGHT
    int startVerticalDraw = (-1) * data()->player.line_height / 2 + SCREEN_HEIGHT / 2;

    // Set data()->var.draw_start to draw_start, but ensure it's not below 0
    data()->player.startVerticalDraw = startVerticalDraw;
    if (data()->player.startVerticalDraw < 0)
        data()->player.startVerticalDraw = 0;

    // Calculate the initial draw_end based on line_height and SCREEN_HEIGHT
    data()->player.endVerticalDraw = data()->player.line_height / 2 + SCREEN_HEIGHT / 2;

    // Ensure that data()->var.draw_end doesn't exceed the screen height
    if (data()->player.endVerticalDraw >= SCREEN_HEIGHT)
        data()->player.endVerticalDraw = SCREEN_HEIGHT - 1;
}
