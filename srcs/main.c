/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:17:48 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/09/27 18:53:11 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
	This function lets us access the static variable type t_data,
	the static variable retains its value between function calls,
	we return a pointer to data as data is static, the memory 
	location is fixed and can be accessed after the function
	finished executing. it helps to	maintain state across 
	different parts of the program and provide a global variable
	like behaviour.
*/
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

int	begin_game(void)
{
	void	*image;
	char	*data_address;

	// Create a new image with MiniLibX with specified dimensions
	image = mlx_new_image(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Store the image pointer in a data structure
	data()->screen.pointer_to_image = image;

	// Retrieve the image properties and its address using mlx function
	data_address = mlx_get_data_address(data()->screen.pointer_to_image,
		&data()->screen.bits_per_pixel, &data()->screen.line_length,
		&data()->screen.endian);

	// Store the image address in a data structure
	data()->screen.address = data_address;

	// Draw the floor of the game environment
	draw_floor();

	// Draw the ceiling of the game environment
	draw_ceiling();

	//player_movement
	player_movement();

	// Set the frame time to 16 milliseconds (ms) per frame, equivalent to 60 frames per second (FPS).
	data()->player.frame_time = 16 / 1000.0;

	// set move speed and rotate speed based on the frame time
	data()->player.move_speed = data()->player.frame_time * 5.0;
	data()->player.rotate_speed = data()->player.frame_time * 3.0;

	// Display the image on the application window
	// 0 , 0 - These are the X and Y coordinates within the window where the top-left corner of the image will be positioned
	mlx_put_image_to_window(data()->mlx, data()->win,
		data()->screen.pointer_to_image, 0, 0);

	// Destroy the image to prevent memory leaks
	mlx_destroy_image(data()->mlx, data()->screen.pointer_to_image);

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
	mlx_loop_hook(data()->mlx, begin_game, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_PRESS, X_NO_EVENT_MASK, &key_press, NULL);
	mlx_hook(data()->win, X_EVENT_KEY_RELEASE, X_NO_EVENT_MASK, &key_release, NULL);
	mlx_hook(data()->win, X_EVENT_DESTROY_NOTIFY, X_NO_EVENT_MASK,
		&exit_game, NULL);
	mlx_loop(data()->mlx);
	return (0);
}
