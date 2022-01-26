SRCS	=	main.c \
			init_game.c \
			load_file.c \
			clear_file.c \
			clear_game.c \
			clear_game_utils.c \
			clear_splitted.c \
			count_splitted.c \
			get_colors.c \
			get_player_position.c \
			get_resolution.c \
			get_texture_path.c \
			load_textures.c \
			parse_map.c \
			validate_map.c \
			error_map_line.c \
			get_next_line.c \
			get_next_line_utils.c \
			create_image.c \
			calculate_ray.c \
			key_events.c \
			movements.c \
			draw_textures.c \
			save_picture.c \
			screenshot.c \
			get_sprites.c \
			sort_sprites.c \
			draw_sprites.c \
			read_line.c \
			exit_game.c \
			count_commas.c

OBJS	= 	$(SRCS:.c=.o)

PRINTF	=	ft_printf/libftprintf.a

MLX 	=	mlx/libmlx.dylib

NAME	=	cub3D

GCC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c		
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):	$(MLX) $(OBJS) $(PRINTF) cub3d.h
			$(GCC) -lmlx libmlx.dylib -framework OpenGL -framework AppKit $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):	
			make -C "ft_printf"

$(MLX):     
			make -C "mlx"
			cp mlx/mlx.h . 
			cp mlx/libmlx.dylib .

clean:		
			$(RM) $(OBJS)
			make clean -C "ft_printf"
			make clean -C "mlx"

fclean:		clean
			$(RM) $(NAME) mlx.h libmlx.dylib picture.bmp
			make fclean -C "ft_printf"
			make clean -C "mlx"

re:			fclean all

.PHONY:		all clean fclean re
