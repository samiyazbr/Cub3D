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

static int	check_and_convert(const char *str, int *value)
{
    int j = 0;

    while (str[j])
    {
        if (!ft_isdigit(str[j]))
            return 0;
        j++;
    }
    *value = ft_atoi(str);
    return 1;
}

static int *validate_rgb(char **array)
{
    int i;
	int *rgb;

	i = 0;
    rgb = malloc(sizeof(int) * 4);
    if (!rgb)
        return NULL;
    while (array[i])
    {
        if (!check_and_convert(array[i], &rgb[i]))
        {
            free(rgb);
            return NULL;
        }
        if (rgb[i] < 0 || rgb[i] > 255)
        {
            free(rgb);
            return NULL;
        }
        i++;
    }
    rgb[i] = 0;
    return rgb;
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

int *validate_and_convert(char **temp)
{
    int *rgb;
	
	rgb = validate_rgb(temp);
    if (!rgb)
    {
        free(rgb);
        return NULL;
    }
    return rgb;
}

int init_colors(void)
{
    int i;
	char **temp;
	int *rgb;

	i = 0;
    while (data()->rgb[i])
    {
        temp = ft_split(data()->rgb[i], ',');
        if (!temp)
        {
            ft_free(&temp);
            return 1;
        }
        rgb = validate_and_convert(temp);
        if (!rgb)
        {
            ft_free(&temp);
            return 1;
        }
        convert_colors(rgb, i);
		free(rgb);
        ft_free(&temp);
        i++;
    }
    return 0;
}
