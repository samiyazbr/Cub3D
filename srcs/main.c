/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:17:48 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/09/25 07:40:49 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

t_data	*data(void)
{
	static t_data	data;
	return (&data);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nPlease Select The Map File");
		return (1);
	}
	parse_cub_file(argv[1]);
	init();
	return (0);
}

