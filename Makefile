NAME = cub3D

CC = cc

C_FLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FUNCTIONS =	map_parsing/check_textures_colors.c\
			map_parsing/rgb_to_hexa.c\
			map_parsing/checking_walls.c\
			map_parsing/check_map_utils.c\
			map_parsing/read_and_add.c\
			map_parsing/main.c\
			map_parsing/check_map_utils2.c\
			map_parsing/map_cheking.c\
			map_parsing/check_Path.c\
			map_parsing/mini_split.c\
			map_parsing/utils.c\
			map_parsing/main_utils.c\
			libft/ft_strcmp.c\
			libft/ft_strtrim.c\
			libft/ft_strlen.c\
			libft/ft_strncmp.c \
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_split.c\
			libft/ft_atoi.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			cub3d.c\
			cubwin.c\
			dslen.c\
			my_mlx_pixel_put.c\
			map_parsing/start.c\
			ft_quit.c\
			keysup.c\
			keysdown.c\
			rays_casting.c\
			file_to_image.c\
			clean_window.c\
			draw_verticaline.c\
			colors.c\
			dstcmp.c\
			cast.c\
			v_points.c\
			v_point1.c\
			h_points.c\
			init_raydir.c\
			anglehandler.c\
			outside_wall.c\
			draw_player1.c\
			draw_player.c\
			get_playerp.c\
			get_wsize.c\
			draw_map.c\
			draw_square.c\
			init_vr.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS) $(FUNCTIONS) $(MLX_FLAGS)  -o $(NAME) 

clean	:	
			$(RM) $(NAME)
fclean	:	clean
		
re 		:	fclean all
