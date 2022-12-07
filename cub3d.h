/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:04:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:33:24 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h> 
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct fd
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	*full_map;
	int		color_c;
	int		color_f;
}	t_fd;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;
typedef struct address
{
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
}			t_address;

typedef struct s_vars
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	t_fd	all_maps;
	char	*fline;
	int		fd;
	int		wsize;
	int		hsize;
	int		ywin;
	int		xwin;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		s;
	int		sy;
	double	px;
	double	py;
	double	dx;
	double	dy;
	int		turndrc;
	int		movedrc;
	double	p_angle;
	double	movepix;
	double	rot_ang;
	double	xjump;
	double	yjump;
	double	fov;
	int		raywth;
	int		rays;
	double	rx;
	double	ry;
	double	distance;
	int		upray;
	int		downray;
	int		rightray;
	int		leftray;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	int		hwall;
	int		vwall;
	double	hx1;
	double	vx2;
	double	hy1;
	double	vy2;
	int		verticalhit;
	double	rw_distance;
	double	player_pplan;
	double	wallheight;
	double	wallheight_hold;
	int		move_directionx;
	int		move_directiony;
	int		move_rotation;
	int		start;
}	t_vars;

size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
void			get_winsize(t_vars *vr);
int				get_wsize(char **map);
int				dslen(char **str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_quit(void);
int				keysup(int keycode, t_vars *vr);
int				keysdown(int keycode, t_vars *vr);
void			rays_casting(t_vars *vr);
void			file_to_image(t_vars *vr, t_address *data);
void			clean_window(t_vars *vr);
void			draw_verticaline(double x, double y,
					t_vars *vr, t_address data);
unsigned int	colors(t_vars *data, t_data textures, int x, int y);
void			dstcmp(t_vars *vr);
void			cast(t_vars *vr, double r_angle);
void			v_points(t_vars *vr, double r_angle);
void			v_point1(t_vars *vr, double deltax, double deltay);
void			h_points(t_vars *vr, double deltax, double deltay);
void			init_raydir(double r_angle, t_vars *vr);
void			anglehandler(double *r_angle);
int				outside_wall(double x, double y, t_vars *vr);
void			draw_player1(t_vars *vr);
void			draw_player(t_vars *vr);
void			get_playerp(t_vars *vr);
int				get_wsize(char **map);
void			draw_map(t_vars *vr);
void			draw_square(t_vars *vr, int color);
void			init_vr(t_vars *vr);

/**********************parsing*************************/

int				len(char **str);
void			ft_free(char **str);
int				check_c(char **str);
int				check_f(char **str);
int				check_so(char **str);
int				counting(char **str);
int				check_we(char **str);
char			*joining(char **str);
int				check_no(char **str);
char			*only_map(char *str);
int				check_ea(char **str);
int				all_walls(char	*str);
t_fd			take_path(char	*str);
int				rgb_to_hexa(char *str);
int				check_comma(char *str);
int				check_player(char str);
t_fd			read_and_add(char **av);
int				map_checking(char *str);
t_fd			read_and_add(char **av);
int				check_isdigit(char **sp);
int				check_newline(char *str);
int				map_checking2(char	*str);
int				last_touches(char	**str);
t_fd			file_dis(char *sp, char *s);
void			edit_spaces(char *str);
char			*no_spaces(char *str);
int				req_zero2(char **str, int start, int i);
int				check_colors_valid2(char **sp_f, char **sp_c);
void			check_extension(char *av[]);
int				last_touches2(int cout_p, int i);
int				check_player(char str);
int				check_f_c(char	**str,	int line);
int				check_spaces(char **str, int start);
int				check_colors_valid(char *F, char *C);
int				check_textures(char **str,	int line);
int				req_zero(char **str, int start, int i);
int				check_walls(char *str, int start, int count);
int				first_forth_lines(char *split_str,	int line);
int				check_comma(char *str);
int				check_walls(char	*str, int start, int count);
int				two_lines_color(char *split_str, int line);
char			*read_file(int fd);
void			fd_protection(int fd);

#endif