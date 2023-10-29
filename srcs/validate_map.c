/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:26:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/22 23:26:57 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_closed_2(int i, int j)
{
	if (data()->map[i] && data()->map[i][j - 1]
			&& data()->map[i][j - 1] == ' ')
		return (1);
	if (data()->map[i] && data()->map[i][j + 1]
		&& data()->map[i][j + 1] == ' ')
		return (1);
	return (0);
}

static int	is_closed(int i, int j)
{
	if (data()->map[i][j] == '0' \
		|| (data()->map[i][j] != '1' && data()->map[i][j] != ' '))
	{
		if (i == 0 || !data()->map[i + 1] || j == 0 || !data()->map[i][j + 1])
			return (1);
		if (data()->map[i - 1] && data()->map[i - 1][j]
			&& data()->map[i - 1][j] == ' ')
			return (1);
		if (data()->map[i + 1] && data()->map[i + 1][j]
			&& data()->map[i + 1][j] == ' ')
			return (1);
		is_closed_2(i, j);
	}
	return (0);
}

static int	is_end(int index)
{
	int	i;

	i = index;
	i++;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) > 0)
			return (1);
		i++;
	}
	data()->map[i] = NULL;
	return (0);
}

static int	validate_map_1(int i, int j)
{
	while (data()->map[i][j])
	{
		if (is_closed(i, j) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	validate_map(void)
{
	int	i;
	int	j;

	formatmap();
	if (ft_array_length(data()->map) < 3 \
		|| check_characters() != 1 || is_map_empty() == 1)
		return (1);
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0)
		{
			if (is_end(i) == 1)
				return (1);
			break ;
		}
		j = 0;
		validate_map_1(i, j);
		i++;
	}
	return (0);
}
