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

void	fill_texture_array(int	i)
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
			(data()->textures[i].address[data()->textures.height * y + x]);
		}
	}
}

int init_textures(void)
{
	int		i;
	void	*temp;
	int		*address;

	i = 0;
	while (i < 4)
	{
		temp = mlx_xpm_file_to_image(data()->mlx, data()->xpm[i], \
			&(data()->textures.width), &(data()->textures.height));
		data()->textures.pointer_to_image = temp;
		if (!data()->textures[i].pointer_to_image)
			return (1);
		address = (int *)mlx_get_data_addr(data()->textures[i].pointer_to_image, \
			&data()->textures.bits_per_pixel, &data()->textures[i].line_length, \
			&data()->textures[i].endian);
		data()->textures.address = address;
		if (!data()->textures[i].address)
			return (1);
		fill_texture_array(i);
		mlx_destroy_image(data()->mlx, data()->textures.pointer_to_image);
		i++;
	}
	return (0);
}

void	init(void)
{
	void	*temp;

	data()->mlx = mlx_init();
	if (init_textures() == 1)
		ft_exit_init("Error\nUnable to Load Textures");
	if (init_colors() == 1)
		ft_exit_init("Error\nUnable to Load Colors");
	if (validate_map() == 1)
		ft_exit_init("Error\nInvalid Map\n");
		temp = mlx_new_window(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D" );
	data()->win = temp;
}
