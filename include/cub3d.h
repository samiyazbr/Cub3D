/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:25:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/11/07 13:51:48 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
#include "../mlx/mlx.h"
// # include "../mlx_linux/mlx.h" 

# define SCREEN_HEIGHT 			1080
# define SCREEN_WIDTH 			1920
// TEXTURE

# define TEXTURE_HEIGHT	64
# define TEXTURE_WIDTH	64

//EVENTS

# define X_EVENT_DESTROY_NOTIFY	17
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_NO_EVENT_MASK 		0

//KEY (mac keys)
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_W 13
// # define KEY_LEFT 123
// # define KEY_RIGHT 124
// # define KEY_ESC 53

// linux key
#define KEY_W 119  // 'W' key on Windows/WSL
#define KEY_S 115  // 'S' key
#define KEY_A 97   // 'A' key
#define KEY_D 100  // 'D' key
#define KEY_ESC 27 // ESC key
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_player
{
	double			position_x;
	double			position_y;
	double			direction_x;
	double			direction_y;
	double			camera_x;
	double			raydirection_x;
	double			raydirection_y;
	double			delta_distance_x;
	double			delta_distance_y;
	double			x_intersection_distance;
	double			y_intersection_distance;
	double			wallintersectionx;
	double			plane_x;
	double			plane_y;
	double			frame_time;
	double			move_speed;
	double			rotate_speed;
	double			movement;
	double			perspective_wall_distance;
	void			*pointer_to_image;
	int				map_x;
	int				map_y;
	int				x_movement;
	int				y_movement;
	int				side;
	int				hit;
	int				texture_y;
	int				texture_x;
	int				texture_id;
	int				line_height;
	int				startverticaldraw;
	int				endverticaldraw ;
	unsigned int	color;
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

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right_key;
	int	left_key;
	int	sprite;
}				t_key;

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

int				parse_cub_file(char *file);
int				ft_array_length(char **array);
void			ft_free(char ***array);
int				init_colors(void);
unsigned long	rgb_to_hex(int red, int green, int blue);
void			convert_colors(int *rgb, int i);
void			fill_texture_array(int i);
int				init_textures(void);
void			init(void);
int				parse_c_f_rgb_textures(int fd);
int				check_characters(void);
int				validate_map(void);
t_data			*data(void);
void			init_directional_vectors(int x, int y);		
int				build_map(char *line);
char			**ft_realloc(char **pointer, int size);
int				key_press(int keycode);
int				begin_game(void);
void			draw_floor(void);
void			draw_ceiling(void);
int				key_release(int keycode);
void			player_movement(void);
void			player_move_forward(void);
void			player_move_backwards(void);
void			player_move_left(void);
void			player_move_right(void);
int				exit_game(void);
void			mlx_place_pixel(int x, int y, int colour);
void			player_rotate_right(void);
void			player_rotate_left(void);
void			raycasting(void);
void			find_rayposition_and_raydirection(int x);
void			set_wall_position(void);
void			set_delta_distance(void);
void			find_x_movement_and_x_intersection_distance(void);
void			find_y_movement_and_y_intersection_distance(void);
void			dda(void);
void			set_texture(void);
void			calculateperspectivewalldistance(void);
void			calculate_vertical_line_height(void);
void			calculateverticaldrawingbounds(void);
void			calculatetexturecoordinatex(void);
void			draw_vertical_texture_stripe(int x);
void			formatmap(void);
int				is_map_empty(void);
int				is_valid_map_line(const char *line);
int				check_skip_line(char *line);
void			ft_error_parse_cub_file(char *msg, int fd);
void			ft_error_cub_file(char *msg, int fd);
void			free_xpm(void);
void			free_rgb(void);
int				process_skip_line(char *line);
int				process_text_line(char *line, int *skip_lines, int *mapempty);
int				process_line_and_check_arrays(char *line);

#endif
