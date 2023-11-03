/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:04:49 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/22 23:04:49 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	*validate_rgb(char **array)
{
	int	i;
	int j;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (array[i])
	{
		        j = 0;
        while (array[i][j])
        {
            if (!ft_isdigit(array[i][j]))
            {
                free(rgb);
                return (1);
            }
            j++;
        }
		rgb[i] = ft_atoi(array[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_colors(int *rgb, int i)
{
	unsigned long	temp;

	if (i == 0)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->floor = temp;
	}
	if (i == 1)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->ceiling = temp;
	}
}

int	init_colors(void)
{
	int		i;
	char	**temp;
	int		*rgb;

	i = 0;
	while (data()->rgb[i])
	{
		temp = ft_split(data()->rgb[i], ',');
		if (!temp)
			return (1);
		rgb = validate_rgb(temp);
		if (!rgb)
		{
			free(rgb);
			return (1);
		}
		convert_colors(rgb, i);
		ft_free(&temp);
		free(rgb);
		i++;
	}
	return (0);
}
