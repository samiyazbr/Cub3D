/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:16:46 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/22 22:16:46 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_exit_init(char *msg)
{
	write(2, msg, ft_strlen(msg));
	ft_free(&data()->xpm);
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

void	fill_texture_array(int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data()->textures[i].height)
	{
		x = -1;
		while (++x < data()->textures[i].width)
		{
			data()->xpm_size[i][data()->textures[i].height * y + x] = \
			(data()->textures[i].address[data()->textures[i].height * y + x]);
		}
	}
}

int	init_textures(void)
{
	int		i;
	void	*temp;
	int		*address;
	size_t	len;

	i = 0;
	while (i < 4)
	{
		len = strlen(data()->xpm[i]);
		if (len > 0 && data()->xpm[i][len -1] == '\n') 
		{
			data()->xpm[i][len - 1] = '\0'; // Replace newline with null terminator
			data()->xpm[i][len - 2] = '\0'; // Replace newline with null terminator
		}
		//printf("Width: %d\n", data()->textures[i].width);
		//printf("Height: %d\n", data()->textures[i].height);
		//for(int j = 0; j < 4; j++)
		//	printf("xpm[%i] = %s" , j, data()->xpm[j]);
		temp = mlx_xpm_file_to_image(data()->mlx, data()->xpm[i], \
			&(data()->textures[i].width), &(data()->textures[i].height));
		data()->textures[i].pointer_to_image = temp;
		// for some reason data()->textures[i].pointer_to_image = 0x0 why?
		// ans: mlx_xpm_file_to_image() was returning NULL bcz while trying
		// to access data()->xpm[i] its causing sig fault (it got fixed while commenting the newly added part).
		
		// printf("Pointer to Image: %p\n", data()->textures[i].pointer_to_image);
		// data()->textures[i].pointer_to_image is still null I think its because somehow file name is also storing a \n at the end
		// this issue got fixed by adding a ' ' at the end of the file name before adding the new line now the error is back to "Invalid information on File"
		if (!data()->textures[i].pointer_to_image)
			return (1);
		
		//printf("Pointer to Image: %p\n", data()->textures[i].pointer_to_image);
		//printf("Address: %p\n", data()->textures[i].address);
		//printf("Bits Per Pixel: %d\n", data()->textures[i].bits_per_pixel);
		//printf("Line Length: %d\n", data()->textures[i].line_length);
		//printf("Endian: %d\n", data()->textures[i].endian);
		//printf("Width: %d\n", data()->textures[i].width);
		//printf("Height: %d\n", data()->textures[i].height);
		address = (int *)mlx_get_data_address(data()->textures[i].pointer_to_image,
				&data()->textures[i].bits_per_pixel,
				&data()->textures[i].line_length, &data()->textures[i].endian);
		data()->textures[i].address = address;
		// data()->textures[i].address is also null why?
		if (!data()->textures[i].address)
			return (1);
		fill_texture_array(i);
		mlx_destroy_image(data()->mlx, data()->textures[i].pointer_to_image);
		i++;
	}
	return (0);
}

void	init(void)
{
	void	*temp;

	data()->mlx = mlx_init();
	if (init_textures() == 1)
		ft_exit_init("Error\nUnable to Load Textures\n");
	if (init_colors() == 1)
		ft_exit_init("Error\nUnable to Load Colors\n");
	if (validate_map() == 1)
		ft_exit_init("Error\nInvalid Map\n");
	temp = mlx_new_window(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D" );
	data()->win = temp;
}
