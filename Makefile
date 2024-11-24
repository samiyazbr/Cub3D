NAME		=	cub3D

LIB_PATH	=	libft/

LIB			=	${LIB_PATH}libft.a

SRCS		= ./srcs/main.c \
				./srcs/parse_cub_file.c \
				./srcs/init_colors.c \
				./srcs/init.c \
				./srcs/parse_c_f_rgb_textures.c \
				./srcs/utils1.c \
				./srcs/validate_map.c \
				./srcs/parse_map.c \
				./srcs/init_directional_vectors.c \
				./srcs/key.c \
				./srcs/player_movement.c \
				./srcs/player_rotation.c \
				./srcs/draw.c \
				./srcs/raycasting.c \
				./srcs/raycasting_2.c \
				./srcs/raycasting_3.c \
				./srcs/build_map.c \
				./srcs/format_map.c \
				./srcs/ft_error.c \

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_PATH	=	./mlx_linux/
	MLX			=	libmlx_Linux.a
	MLXFLAGS	=	-lm -lbsd -lmlx -lXext -lX11
	CC			=	clang
	CFLAGS		=	-Wall -Werror -Wextra -gdwarf-4
else
	MLX_PATH	=	./mlx/
	MLX			=	libmlx.a
	MLXFLAGS	=	-L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit
	CC			=	cc
	CFLAGS		=	-Wall -Werror -Wextra ${HEADER}
endif


HEADER		=	-I include/
OBJS		=	${SRCS:.c=.o}


OBJS_FILES = $(OBJS)

.PHONY		:	all libft_lib clean fclean re bonus

all			:	lib_mlx libft_lib ${NAME}

lib_mlx:	
				make -C ${MLX_PATH} all

libft_lib	:	
				make -C ${LIB_PATH} all

${NAME}		:	${OBJS_FILES}
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS_FILES) -L $(LIB_PATH) -L $(MLX_PATH) -lft $(MLXFLAGS) 

clean		:	
				make -C ${MLX_PATH} clean
				make -C ${LIB_PATH} clean
				rm -rf ${OBJS}

fclean		:	clean
				make -C ${LIB_PATH} fclean
				rm -rf ${NAME}

re			:	fclean all


