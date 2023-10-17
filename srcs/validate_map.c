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

static char	*ft_strchr_mod(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

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
			if (!ft_strchr_mod(" 10NSEW", data()->map[i][j]))
			{
				return (0);
			}
			if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' \
				|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
			{
				init_directional_vectors(j, i);
				count++;
			}
			j++;
		}
				printf("%c\n", data()->map[i][j]);
		i++;
	}
	printf("count: %d\n", count);
	return (count);
}

// static int	is_closed(int i, int j)
// {
// 	if (data()->map[i][j] == 0 \
// 		|| (data()->map[i][j] != '1' && data()->map[i][j] != ' '))
// 	{
// 		if (i == 0 || !data()->map[i + 1] || j == 0 || !data()->map[j + 1])
// 			return (1);
// 		if (data()->map[i - 1] && data()->map[i - 1][j] &&
// 			data()->map[i - 1][j] == ' ')
// 			return (1);
// 		if (data()->map[i + 1] && data()->map[i + 1][j] &&
// 			data()->map[i + 1][j] == ' ')
// 			return (1);
// 		if (data()->map[i] && data()->map[i][j - 1] &&
// 			data()->map[i][j - 1] == ' ')
// 			return (1);
// 		if (data()->map[i] && data()->map[i][j + 1] &&
// 			data()->map[i][j + 1] == ' ')
// 			return (1);
// 	}
// 	return (0);
// }

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
		if (data()->map[i] && data()->map[i][j - 1]
			&& data()->map[i][j - 1] == ' ')
			return (1);
		if (data()->map[i] && data()->map[i][j + 1]
			&& data()->map[i][j + 1] == ' ')
			return (1);
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
			return (1);  // this was returning i instead of 1
		i++;
	}
	data()->map[i] = NULL;
	return (0);
}

//now this function is returning 1
int	validate_map(void)
{
	int	i;
	int	j;
	// printf("data()->map = %d\n", ft_array_length(data()->map));
	if (ft_array_length(data()->map) < 3 || check_characters() != 1){
		// printf("check_characters is returning 0");
		printf("check_char() = %d\n", check_characters());
		// printf("i am here\n");
		return (1);
	}
	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == 0)
		{
			if (is_end(i) == 1)
			{
				printf("is_end is returning 1");
				return (1);
			}
			break ;
		}
		j = 0;
		while (data()->map[i][j])
		{
			if (is_closed(i, j) == 1)
			{
				printf("is_closed is returning 1");
				return (1);
			}
			
			j++;
		}
		i++;
	}
	return (0);
}
