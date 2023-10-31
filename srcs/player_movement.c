/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:57:44 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/31 15:31:59 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_movement(void)
{
	if (data()->key.w == 1)
		player_move_forward();
	if (data()->key.s == 1)
		player_move_backwards();
	if (data()->key.a == 1)
		player_move_left();
	if (data()->key.d == 1)
		player_move_right();
	if (data()->key.left_key == 1)
		player_rotate_left();
	if (data()->key.right_key == 1)
		player_rotate_right();
}

void	player_move_forward(void)
{
	int	y;
	int	x;

	y = (int)data()->player.position_y;
	x = (int)(data()->player.position_x + data()->player.direction_x
			* data()->player.move_speed);
	if (data()->map[y][x] != '1')
		data()->player.position_x += data()->player.direction_x
		* data()->player.move_speed;
	y = (int)(data()->player.position_y + data()->player.direction_y
			* data()->player.move_speed);
	x = (int)data()->player.position_x;
	if (data()->map[y][x] != '1')
		data()->player.position_y += data()->player.direction_y
		* data()->player.move_speed;
}

void	player_move_backwards(void)
{
	int	y;
	int	x;

	y = (int)data()->player.position_y;
	x = (int)(data()->player.position_x - data()->player.direction_x
			* data()->player.move_speed);
	if (data()->map[y][x] != '1')
		data()->player.position_x -= data()->player.direction_x
		* data()->player.move_speed;
	y = (int)(data()->player.position_y - data()->player.direction_y
			* data()->player.move_speed);
	x = (int)data()->player.position_x;
	if (data()->map[y][x] != '1')
		data()->player.position_y -= data()->player.direction_y
		* data()->player.move_speed;
}

void	player_move_left(void)
{
	int	y;
	int	x;

	y = (int)data()->player.position_y;
	x = (int)(data()->player.position_x + data()->player.direction_y
			* data()->player.move_speed);
	if (data()->map[y][x] != '1')
		data()->player.position_x += data()->player.direction_y
		* data()->player.move_speed;
	y = (int)(data()->player.position_y - data()->player.direction_x
			* data()->player.move_speed);
	x = (int)data()->player.position_x;
	if (data()->map[y][x] != '1')
		data()->player.position_y -= data()->player.direction_x
		* data()->player.move_speed;
}

void	player_move_right(void)
{
	int	y;
	int	x;

	y = (int)data()->player.position_y;
	x = (int)(data()->player.position_x - data()->player.direction_y
			* data()->player.move_speed);
	if (data()->map[y][x] != '1')
		data()->player.position_x -= data()->player.direction_y
		* data()->player.move_speed;
	y = (int)(data()->player.position_y + data()->player.direction_x
			* data()->player.move_speed);
	x = (int)data()->player.position_x;
	if (data()->map[y][x] != '1')
		data()->player.position_y += data()->player.direction_x
		* data()->player.move_speed;
}
