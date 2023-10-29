/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:59:04 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/29 13:04:19 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_map_dimensions(int *num_rows, int *max_length, int *length)
{
	*num_rows = 0;
	*max_length = 0;
	*length = 0;
	while (data()->map[*num_rows])
	{
		*length = ft_strlen(data()->map[*num_rows]);
		if (*length > *max_length)
		{
			*max_length = *length;
		}
		(*num_rows)++;
	}
}

static void	initialize_new_map(char *new_map[], int num_rows, int max_length)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	while (i < num_rows)
	{
		new_map[i] = malloc(max_length + 1);
		strcpy(new_map[i], data()->map[i]);
		length = strlen(new_map[i]);
		j = length;
		while (j < max_length)
		{
			new_map[i][j] = ' ';
			j++;
		}
		new_map[i][max_length] = '\0';
		i++;
	}
}

void	formatmap(void)
{
	int		num_rows;
	int		max_length;
	int		length;
	int		i;
	char	**new_map;

	num_rows = 0;
	max_length = 0;
	length = 0;
	calculate_map_dimensions(&num_rows, &max_length, &length);
	new_map = (char **)malloc(num_rows * sizeof(char *));
	if (new_map)
	{
		initialize_new_map(new_map, num_rows, max_length);
		i = 0;
		while (i < num_rows)
		{
			free(data()->map[i]);
			data()->map[i] = new_map[i];
			i++;
		}
		free(new_map);
	}
}
