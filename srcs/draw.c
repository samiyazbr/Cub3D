/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:07:23 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/26 19:43:57 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
			mlx_place_pixel(i, j, data()->ceilling);
			j++;
		}
		i++;
	}
}
