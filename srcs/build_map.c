/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:47:53 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/10/28 19:02:51 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int is_map_empty(void) 
{
    int i = 0;
    while (data()->map[i]) {
        if (strlen(data()->map[i]) > 0) {
            return 0; // Map is not empty
        }
        i++;
    }
    return 1; // Map is empty
}

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
	new_pointer[i + 1] = NULL;
	free(pointer);
	return (new_pointer);
}

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