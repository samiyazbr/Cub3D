/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:53:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/29 15:25:34 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_characters(void)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", data()->map[i][j]))
				return (0);
			if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' \
				|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
			{
				init_directional_vectors(j, i);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_valid_map_character(char c)
{
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E');
}

static int	is_valid_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_valid_map_character(line[i]))
		i++;
	return (line[i] == '\0');
}

int	parse_map(int fd)
{
	char	*line;
	int		mapempty;

	mapempty = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_strtrim(line, "\n");
		if (ft_strlen(line) == 0 && !data()->map)
			continue ;
		if (ft_strlen(line) == 0 || (is_valid_map_line(line)
				&& build_map(line) == 1))
		{
			free(line);
			return (1);
		}
		free(line);
		mapempty = 0;
	}
	if (mapempty)
		return (1);
	return (0);
}
