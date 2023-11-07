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

void	free_xpm(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data()->xpm[i])
		{
			free(data()->xpm[i]);
			data()->xpm[i] = NULL;
		}
		i++;
	}
}

void	free_rgb(void)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data()->rgb[i])
		{
			free(data()->rgb[i]);
			data()->rgb[i] = NULL;
		}
		i++;
	}
}

const char	*find_dot_in_file_name(const char *file)
{
	const char	*dot;
	int			dotcount;
	int			i;

	i = 0;
	dotcount = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			dot = file + i;
			dotcount++;
		}
		i++;
	}
	if (dotcount == 1)
		return (dot + 1);
	else
		return ("");
}

int	process_text_line(char *line, int *skip_lines, int *mapempty)
{
	int	result;

	if (ft_strlen(line) == 0 && !data()->map)
		return (0);
	if (ft_strlen(line) == 0)
		return (1);
	if (process_line_and_check_arrays(line) == 1)
		return (1);
	if (*skip_lines)
	{
		if (is_valid_map_line(line))
			*skip_lines = 0;
		else
		{
			result = process_skip_line(line);
			if (result != 0)
				return (result);
		}
	}
	if (!(*skip_lines) && check_skip_line(line) == 1)
		return (1);
	*mapempty = 0;
	return (0);
}

int	parse_cub_file(char *file)
{
	int	fd;

	if (ft_strncmp(find_dot_in_file_name(file), "cub", 4) != 0)
		ft_error_cub_file("Error\nWrong Extension\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_cub_file("Error\nCannot open the file\n", fd);
	if (parse_c_f_rgb_textures(fd) == 1)
		ft_error_parse_cub_file("Error\nInvalid Information on File\n", fd);
	close (fd);
	return (0);
}
