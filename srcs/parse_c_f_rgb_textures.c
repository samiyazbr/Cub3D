/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c_f_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:57:39 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/21 23:57:39 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*data(void)
{
	static t_data	data;
	return (&data);
}

static int	parse_textures(char *line)
{
	char	**tokens;

	tokens = ft_split(line, " ");
	if (!tokens)
		return (1);
	if (ft_array_lenght(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "NO", 3) == 0)
		data()->xpm[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 3) == 0)
		data()->xpm[1] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 3) == 0)
		data()->xpm[2] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 3) == 0)
		data()->xpm[3] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 2) \
		&& ft_strncmp(tokens[0], "F", 2))
		return (1);
	ft_free(&tokens);
	return (0);
}

static int	parse_rgb(char *line)
{
	char	**tokens;

	tokens = ft_split(line, " ");
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
		return (1);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		data()->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	parse_c_f_rgb_textures(int fd)
{
	char	*line;

	data()->xpm = ft_calloc(sizeof(char *), 5);
	if (!data()->xpm)
		return (1);
	data()->rgb = ft_calloc(sizeof(char *), 3);
	if (!data->rgb)
		return (1);
	while (ft_array_length(data()->xpm) != 4 \
		|| ft_array_length(data()->rgb) !=4)
		{
			line = get_next_line(fd);
			if (ft_strlen(line) == 0)
				return (1);
			else if (parse_textures(line) == 1 || parse_rgb(line) == 1)
			{
				free(line);
				return (1);
			}
			free(line);
			break;
		}
		return (0);
}
