/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubwin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:06:07 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:21:56 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation(t_vars *vr)
{
	vr->p_angle += vr->move_rotation * vr->rot_ang;
}

void	move_w_s(t_vars *vr)
{
	double	step;
	double	new_px;
	double	new_py;

	new_px = 0;
	new_py = 0;
	step = vr->move_directiony * vr->movepix;
	new_px = vr->px + cos(vr->p_angle) * step;
	new_py = vr->py + sin(vr->p_angle) * step;
	if (outside_wall(new_px, new_py, vr))
	{
		vr->px = new_px;
		vr->py = new_py;
	}	
}

void	move_d_a(t_vars *vr)
{
	double	move_angle;
	double	new_px;
	double	new_py;

	new_px = 0;
	new_py = 0;
	if (vr->move_directionx)
	{
		move_angle = (M_PI / 2) * vr->move_directionx;
		new_px = vr->px + cos(vr->p_angle + move_angle) * vr->movepix;
		new_py = vr->py + sin(vr->p_angle + move_angle) * vr->movepix;
		if (outside_wall(new_px, new_py, vr))
		{
			vr->px = new_px;
			vr->py = new_py;
		}
	}
}

int	draw(t_vars *vr)
{
	rotation(vr);
	move_w_s(vr);
	move_d_a(vr);
	clean_window(vr);
	rays_casting(vr);
	mlx_put_image_to_window(vr->mlx, vr->mlx_win, vr->img.img, 0, 0);
	return (1);
}

void	get_winsize(t_vars *vr)
{
	vr->wsize = get_wsize(vr->map);
	vr->hsize = dslen(vr->map);
	vr->xwin = (50 * vr->wsize);
	vr->ywin = (50 * vr->hsize);
	vr->rays = vr->xwin / vr->raywth;
	vr->mlx = mlx_init();
	vr->mlx_win = mlx_new_window(vr->mlx, vr->xwin, vr->ywin, "CUB3D");
	vr->img.img = mlx_new_image(vr->mlx, vr->xwin, vr->ywin);
	vr->img.addr = mlx_get_data_addr(vr->img.img, &(vr->img.bits_per_pixel),
			&(vr->img.line_length), &(vr->img.endian));
	get_playerp(vr);
	vr->player_pplan = (vr->xwin / 2) / tan(vr->fov / 2);
	rays_casting(vr);
	mlx_put_image_to_window(vr->mlx, vr->mlx_win, vr->img.img, 0, 0);
	mlx_hook(vr->mlx_win, 2, 0, keysdown, vr);
	mlx_hook(vr->mlx_win, 3, 0, keysup, vr);
	mlx_hook(vr->mlx_win, 17, 0, ft_quit, 0);
	mlx_loop_hook(vr->mlx, draw, vr);
	mlx_loop(vr->mlx);
}
