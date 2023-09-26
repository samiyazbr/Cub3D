/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:03:19 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/26 14:05:42 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
	{
		printf("You Enter the ESC Key. Good Bye!\n");
		quit_game();
	}
	else if (keycode == KEY_W)
		data()->key.W = 1;
	else if (keycode == KEY_S)
		data()->key.S = 1;
	else if (keycode == KEY_A)
		data()->key.A = 1;
	else if (keycode == KEY_D)
		data()->key.D = 1;
	else if (keycode == KEY_LEFT)
		data()->key.left_key = 1;
	else if (keycode == KEY_RIGHT)
		data()->key.right_key = 1;
	return (0);
}
