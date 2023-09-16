/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:25:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/08/22 23:24:55 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/inc/libft.h"
# include "../mlx_linux/mlx.h" 

# define	SCREEN_HEIGHT	1200
# define	SCREEN_HEIGHT	800
// TEXTURE

# define	TEXTURE_HEIGHT	64
# define	TEXTURE_WIDTH	64

typedef struct s_screen
{
	void	*pointer_to_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_screen;

typedef struct s_textures
{
	void	*pointer_to_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		length;
}	t_textures;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_screen		screen;
	t_textures		textures;
	char			**rgb;
	char			**xpm;
	char			**map;
	unsigned long	floor;
	unsigned long	ceiling;
	int				xpm_size[4][TEXTURE_HEIGHT * TEXTURE_WIDTH];
}	t_data;

int				parse_cub_file(char *file);
static void		ft_error_parse_cub_file(char *msg, int fd);
int				ft_array_length(char **array);
void			ft_free(char **array);
int				init_colors(void);
unsigned long	rgb_to_hex(int red, int green, int blue);


#endif