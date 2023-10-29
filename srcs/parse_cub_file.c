/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:35:40 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/21 23:35:40 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_error_parse_cub_file(char *msg, int fd)
{
	if (fd < 0)
		close(fd);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

const char	*find_dot_in_file_name(const char *file)
{
	const char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		return ("");
	return (dot + 1);
}

int	parse_cub_file(char *file)
{
	int	fd;
	int	fd1;

	if (ft_strncmp(find_dot_in_file_name(file), "cub", 4) != 0)
		ft_error_parse_cub_file("Error\nWrong Extension\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_parse_cub_file("Error\nCannot open the file\n", fd);
	if (parse_c_f_rgb_textures(fd) == 1)
		ft_error_parse_cub_file("Error\nInvalid Information on File\n", fd);
	close (fd);
	fd1 = open(file, O_RDONLY);
	if (fd1 < 0)
		ft_error_parse_cub_file("Error\nCannot open the file\n", fd1);
	if (parse_map(fd1) == 1)
		ft_error_parse_cub_file("Error\nMap Parse Failed\n", fd1);
	close (fd1);
	return (0);
}
