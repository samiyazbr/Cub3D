/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:10:09 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/31 15:30:40 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculatetexturecoordinatex(void)
{
	if (data()->player.side == 0)
		data()->player.wallintersectionx = data()->player.position_y
		+ data()->player.perspective_wall_distance
		* data()->player.raydirection_y;
	else
		data()->player.wallintersectionx = data()->player.position_x
		+ data()->player.perspective_wall_distance
		* data()->player.raydirection_x;
	data()->player.wallintersectionx -= floor(data()->player.wallintersectionx);
	data()->player.texture_x = (int)(data()->player.wallintersectionx \
	* (double)TEXTURE_WIDTH);
	if (data()->player.side == 0 && data()->player.raydirection_x > 0)
		data()->player.texture_x = TEXTURE_WIDTH - data()->player.texture_x - 1;
	if (data()->player.side == 1 && data()->player.raydirection_y < 0)
		data()->player.texture_x = TEXTURE_WIDTH - data()->player.texture_x - 1;
}

void	draw_vertical_texture_stripe(int x)
{
	double	movement;
	double	texture_position;
	int		y;

	movement = 1.0 * TEXTURE_HEIGHT / data()->player.line_height;
	texture_position = (data()->player.startverticaldraw - SCREEN_HEIGHT / 2
			+ data()->player.line_height / 2) * movement;
	y = data()->player.startverticaldraw;
	while (y < data()->player.endverticaldraw)
	{
		data()->player.texture_y = (int)texture_position & (TEXTURE_HEIGHT - 1);
		texture_position += movement;
		data()->player.color = \
		data()->xpm_size[data()->player.texture_id][TEXTURE_HEIGHT \
		* data()->player.texture_y + data()->player.texture_x];
		if (data()->player.side == 1)
			data()->player.color = (data()->player.color >> 1) & 8355711;
		mlx_place_pixel(x, y, data()->player.color);
		y++;
	}
}

void	calculate_vertical_line_height(void)
{
	data()->player.line_height = (int)(SCREEN_HEIGHT \
	/ data()->player.perspective_wall_distance);
}

void	calculateverticaldrawingbounds(void)
{
	int	startverticaldraw;

	startverticaldraw = (-1) * data()->player.line_height / 2 + SCREEN_HEIGHT
		/ 2;
	data()->player.startverticaldraw = startverticaldraw;
	if (data()->player.startverticaldraw < 0)
		data()->player.startverticaldraw = 0;
	data()->player.endverticaldraw = data()->player.line_height / 2
	+ SCREEN_HEIGHT / 2;
	if (data()->player.endverticaldraw >= SCREEN_HEIGHT)
		data()->player.endverticaldraw = SCREEN_HEIGHT - 1;
}