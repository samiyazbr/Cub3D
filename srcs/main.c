/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:17:48 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/09/26 13:58:58 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	exit_game(void)
{
	printf("Exit game!\n");
	mlx_destroy_window(data()->mlx, data()->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nPlease Select The Map File");
		return (1);
	}
	parse_cub_file(argv[1]);
	init();
	mlx_hook(data()->win, X_EVENT_KEY_PRESS, X_NO_EVENT_MASK, &key_press, NULL);
	mlx_hook(data()->win, X_EVENT_DESTROY_NOTIFY, X_NO_EVENT_MASK,
		&exit_game, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
