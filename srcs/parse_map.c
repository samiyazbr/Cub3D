/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:53:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/11/04 19:47:32 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

static int	check_skip_line(char *line)
{
	if (is_valid_map_line(line))
	{
		if (build_map(line) == 1)
		{
			free(line);
			return (1);
		}
	}
	else
		return (1);
	return (0);
}

int	parse_map(int fd)
{
	char	*line;
	int		mapempty;
	int		skip_lines;

	mapempty = 1;
	skip_lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_strtrim(line, "\n");
		if (ft_strlen(line) == 0 && !data()->map)
			continue ;
		if (skip_lines && is_valid_map_line(line))
			skip_lines = 0;
		if (!skip_lines)
			if (check_skip_line(line) == 1)
				return (1);
		free(line);
		mapempty = 0;
	}
	if (mapempty)
		return (1);
	return (0);
}
