/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:07:23 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/31 16:14:10 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_place_pixel(int x, int y, int colour)
{
	char	*distance;

	distance = data()->screen.address + \
		(y * data()->screen.line_length + \
		x * (data()->screen.bits_per_pixel / 8));
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
			mlx_place_pixel(i, j, data()->ceiling);
			j++;
		}
		i++;
	}
}
