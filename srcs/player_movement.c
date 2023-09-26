/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:57:44 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/09/26 15:59:37 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (data()->key.left_key == 1)
		player_rotate_left();
	if (data()->key.right_key == 1)
		player_rotate_right();
}