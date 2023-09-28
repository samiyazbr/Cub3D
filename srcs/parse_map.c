/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:53:24 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/09/28 22:58:44 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**ft_realloc(char **pointer, int size)
{
	int		i;
	char	**new_pointer;

	i = 0;
	new_pointer = malloc(sizeof(char *) * size);
	if (!new_pointer)
		return (NULL);
	while (pointer[i])
	{
		new_pointer[i] = pointer[i];
		i++;
	}
	new_pointer[i] = NULL;
	free(pointer);
	return (new_pointer);
}
/*
This function helps to build the map dynamically. It checks
whether there is an existing map and if it is found it expands
the existing map to accomodate additional lines else it
initializes a new map.
*/
int	build_map(char *line)
{
	char	**temp;

	if (!data()->map)
	{
		data()->map = malloc(sizeof(char *) * 2);
		if (!data()->map)
			return (1);
		data()->map[0] = ft_strdup(line);
		data()->map[1] = NULL;
	}
	else
	{
		temp = ft_realloc(data()->map, ft_array_length(data()->map) + 2);
		if (!temp)
			return (1);
		data()->map = temp;
		data()->map[ft_array_length(data()->map)] = ft_strdup(line);
	}
	return (0);
}
