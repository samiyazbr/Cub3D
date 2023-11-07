/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:53:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/11/07 13:38:25 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_valid_map_character(char c)
{
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E');
}

int	is_valid_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_valid_map_character(line[i]))
		i++;
	return (line[i] == '\0');
}

int	check_skip_line(char *line)
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

static int	strncmp_tokens(char **tokens)
{
	return (ft_strncmp(tokens[0], "NO", 3) == 0 \
				||ft_strncmp(tokens[0], "EA", 3) == 0 \
				||ft_strncmp(tokens[0], "SO", 3) == 0 \
				||ft_strncmp(tokens[0], "WE", 3) == 0 \
				||ft_strncmp(tokens[0], "C", 2) == 0 \
				||ft_strncmp(tokens[0], "F", 2) == 0
	);
}

int	process_skip_line(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (1);
	if (strncmp_tokens(tokens))
	{
		ft_free(&tokens);
		return (0);
	}
	else
	{
		if (!is_valid_map_line(line))
		{
			ft_free(&tokens);
			return (1);
		}
	}
	ft_free(&tokens);
	return (0);
}
