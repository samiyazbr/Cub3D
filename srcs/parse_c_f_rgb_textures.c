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

static int	parse_textures(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
	{
		ft_free(&tokens);
		return (1);
	}
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

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (ft_array_length(tokens) != 2)
	{
		ft_free(&tokens);
		return (1);
	}
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		data()->rgb[0] = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "C", 1) == 0)
		data()->rgb[1] = ft_strdup(tokens[1]);
	ft_free(&tokens);
	return (0);
}

int	allocate_xpm_rgb(void)
{
	data()->xpm = ft_calloc(sizeof(char *), 5);
	if (!data()->xpm)
		return (1);
	data()->rgb = ft_calloc(sizeof(char *), 3);
	if (!data()->rgb)
		return (1);
	return (0);
}

int	process_line_and_check_arrays(char *line)
{
	if (ft_array_length(data()->xpm) != 4 || ft_array_length(data()->rgb) != 2)
	{
		if (parse_textures(line) == 1 || parse_rgb(line) == 1)
		{
			return (1);
		}
	}
	return (0);
}

int	parse_c_f_rgb_textures(int fd)
{
	int		mapempty;
	int		skip_lines;
	char	*line;
	int		result;
	char	*line_with_newline;

	mapempty = 1;
	skip_lines = 1;
	allocate_xpm_rgb();
	while (1)
	{
		line_with_newline = get_next_line(fd);
		if (!line_with_newline)
		{
			free(line_with_newline);
			break ;
		}
		line = ft_strtrim(line_with_newline, "\n");
		free(line_with_newline);
		result = process_text_line(line, &skip_lines, &mapempty);
		free(line);
		if (result != 0)
			return (result);
	}
	return (mapempty);
}

// int	parse_c_f_rgb_textures(int fd)
// {
// 	char	*line;
// 	char	*line_with_newline;
// 	int		skip_lines;
// 	int		mapempty;

// 	mapempty = 1;
// 	skip_lines = 1;
// 	allocate_xpm_rgb();
// 	while (1)
// 	{
// 		line_with_newline = get_next_line(fd);
// 		if (!line_with_newline)
// 		{
// 			free(line_with_newline);
// 			break ;
// 		}
// 		line = ft_strtrim(line_with_newline, "\n");
// 		free(line_with_newline);
// 		if (ft_strlen(line) == 0 && !data()->map)
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		if (ft_strlen(line) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		else if (process_line_and_check_arrays(line) == 1)
// 			return (1);
// 		else if (skip_lines)
// 		{
// 			if (is_valid_map_line(line))
// 				skip_lines = 0;
// 			else
// 				{
// 					char	**tokens;

// 					tokens = ft_split(line, ' ');
// 					if (!tokens)
// 						return (1);
// 				if (ft_strncmp(tokens[0], "NO", 3) == 0 || 
// 					ft_strncmp(tokens[0], "EA", 3) == 0 ||
// 					ft_strncmp(tokens[0], "SO", 3) == 0 ||
// 					ft_strncmp(tokens[0], "WE", 3) == 0 ||
// 					ft_strncmp(tokens[0], "C", 2) == 0 ||
// 					ft_strncmp(tokens[0], "F", 2) == 0
// 				)
// 				{
// 					free(line);
// 					ft_free(&tokens);
// 					continue;
// 				}
// 				else
// 				{
// 					if(!is_valid_map_line(line))
// 					{
// 						free(line);
// 						ft_free(&tokens);
// 						return 1;
// 					}
// 				}
// 			}
// 		}
// 		if (!skip_lines)
// 			if (check_skip_line(line) == 1)
// 				return (1);
// 		free(line);
// 		mapempty = 0;
// 	}
// 	if (mapempty)
// 		return (1);
// 	return (0);
// }
