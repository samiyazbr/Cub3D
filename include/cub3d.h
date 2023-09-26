/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:25:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/09/26 13:49:00 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h" 

# define	SCREEN_HEIGHT	1200
# define	SCREEN_WIDTH	800
// TEXTURE

# define	TEXTURE_HEIGHT	64
# define	TEXTURE_WIDTH	64

//EVENTS

# define	X_EVENT_DESTROY_NOTIFY	17
# define	X_EVENT_KEY_PRESS		2
# define 	X_NO_EVENT_MASK 		0

//KEY
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_player
{
	double		position_x;
	double		position_y;
	double		direction_x;
	double		direction_y;
	double		plane_x;
	double		plane_y;
}	t_player;

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
	int		*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_textures;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_screen		screen;
	t_textures		textures[4];
	char			**rgb;
	char			**xpm;
	char			**map;
	unsigned long	floor;
	unsigned long	ceiling;
	int				xpm_size[4][TEXTURE_HEIGHT * TEXTURE_WIDTH];
	t_player		player;
	t_key			key;
}	t_data;

typedef struct s_key
{
	int	W;
	int	S;
	int	A;
	int	D;
	int	right_key;
	int	left_key;
	int	player;
}				t_key;

int				parse_cub_file(char *file);
int				ft_array_length(char **array);
void			ft_free(char **array);
int				init_colors(void);
unsigned long	rgb_to_hex(int red, int green, int blue);
void			convert_colors(int *rgb, int i);
void			fill_texture_array(int	i);
int 			init_textures(void);
void			init(void);
int				parse_c_f_rgb_textures(int fd);
int				check_characters(void);
int				validate_map(void);
t_data			*data(void);
void			init_directional_vectors(int x, int y);		
int				parse_map(int fd);
char			**ft_realloc(char **pointer, int size);
int				key_press(int keycode)


#endif