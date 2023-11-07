/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:48:14 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/11/06 19:48:14 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error_parse_cub_file(char *msg, int fd)
{
	if (fd < 0)
		close(fd);
	write(2, msg, ft_strlen(msg));
	free_xpm();
	ft_free(&data()->xpm);
	free_rgb();
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

void	ft_error_cub_file(char *msg, int fd)
{
	if (fd < 0)
		close(fd);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
