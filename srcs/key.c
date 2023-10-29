/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:03:19 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/29 16:06:05 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
	{
		printf("You Enter the ESC Key. Good Bye!\n");
		exit_game();
	}
	else if (keycode == KEY_W)
		data()->key.w = 1;
	else if (keycode == KEY_S)
		data()->key.s = 1;
	else if (keycode == KEY_A)
		data()->key.a = 1;
	else if (keycode == KEY_D)
		data()->key.d = 1;
	else if (keycode == KEY_LEFT)
		data()->key.left_key = 1;
	else if (keycode == KEY_RIGHT)
		data()->key.right_key = 1;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == KEY_W)
		data()->key.w = 0;
	else if (keycode == KEY_S)
		data()->key.s = 0;
	else if (keycode == KEY_A)
		data()->key.a = 0;
	else if (keycode == KEY_D)
		data()->key.d = 0;
	else if (keycode == KEY_LEFT)
		data()->key.left_key = 0;
	else if (keycode == KEY_RIGHT)
		data()->key.right_key = 0;
	return (0);
}
