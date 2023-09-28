/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:07:23 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/27 18:52:09 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void mlx_place_pixel(int x, int y, int colour)
{
    // Calculate the memory address where the pixel should be placed
    char *distance = data()->screen.address + \
        (y * data()->screen.line_length + x * (data()->screen.bits_per_pixel / 8));

    // Set the color value at the calculated memory address
    *(unsigned int *)distance = colour;
}


void	draw_floor(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2;
		while (j < SCREEN_HEIGHT)
		{
			// Place a pixel at the current (i, j) coordinates on the screen using the floor color
			mlx_place_pixel(i, j, data()->floor);
			j++;
		}
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT / 2)
		{
			// Place a pixel at the current (i, j) coordinates on the screen using the ceiling color
			mlx_place_pixel(i, j, data()->ceiling);
			j++;
		}
		i++;
	}
}
