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

int	validat_map(void)
{
	int	i;
	int	j;

	if (ft_array_length(data()->map) < 3 || check_characters() != 1)
		return (1);
}