/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:10:09 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/05 14:19:05 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void calculateTextureCoordinateX(void)
{
    // Calculate the x-coordinate of the point where the ray hits the wall
    if (data()->player.side == 0)
        data()->player.wallIntersectionX = data()->player.position_y + data()->player.perspective_wall_distance * data()->player.raydirection_y;
    else
        data()->player.wallIntersectionX = data()->player.position_x + data()->player.perspective_wall_distance * data()->player.raydirection_x;
    
    // Adjust the wallIntersectionX to be a value between 0 and 1
    data()->player.wallIntersectionX -= floor(data()->player.wallIntersectionX);

    // Calculate the x-coordinate on the texture where the ray hits
    data()->player.texture_x = (int)(data()->player.wallIntersectionX * (double)TEXTURE_WIDTH);

    // If the ray hit a wall on the left side and is moving right, adjust texture_x
    if (data()->player.side == 0 && data()->player.raydirection_x > 0)
        data()->player.texture_x = TEXTURE_WIDTH - data()->player.texture_x - 1;

    // If the ray hit a wall on the right side and is moving left, adjust texture_x
    if (data()->player.side == 1 && data()->player.raydirection_y < 0)
        data()->player.texture_x = TEXTURE_WIDTH - data()->player.texture_x - 1;
}

void draw_vertical_texture_stripe(int x)
{
    // Calculate the movement size for texture mapping
    double movement = 1.0 * TEXTURE_HEIGHT / data()->player.line_height;

    // Calculate the initial texture_position based on draw_start, screen height, and line height
    double texture_position = (data()->player.startVerticalDraw - SCREEN_HEIGHT / 2 + data()->player.line_height / 2) * movement;

    // Initialize the y-coordinate to draw from draw_start
    int y = data()->player.startVerticalDraw;

    // Iterate through the vertical range from draw_start to draw_end
    while (y < data()->player.endVerticalDraw)
    {
        // Calculate the texture coordinate in the y-axis
        data()->player.texture_y = (int)texture_position & (TEXTURE_HEIGHT - 1);

        // Increment the texture position by the movement
        texture_position += movement;

        // Retrieve the color value from the texture map
        data()->player.color = data()->xpm_size[data()->player.texture_id][TEXTURE_HEIGHT * data()->player.texture_y + data()->player.texture_x];

        // If the wall is on the side, apply a shading effect by reducing the color intensity
        if (data()->player.side == 1)
            data()->player.color = (data()->player.color >> 1) & 8355711;

        // Place the pixel with the calculated color on the screen
        mlx_place_pixel(x, y, data()->player.color);

        // Move to the next vertical position
        y++;
    }
}

