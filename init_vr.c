/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:05:24 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 16:11:47 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vr2(t_vars *vr)
{
	vr->hx1 = 0;
	vr->hy1 = 0;
	vr->vx2 = 0;
	vr->vy2 = 0;
	vr->verticalhit = 0;
	vr->rw_distance = 0;
	vr->player_pplan = 0;
	vr->wallheight = 0;
	vr->move_directionx = 0;
	vr->move_directiony = 0;
	vr->move_rotation = 0;
}

void	init_vr1(t_vars *vr)
{
	vr->turndrc = 0;
	vr->movedrc = 0;
	vr->p_angle = 0;
	vr->movepix = 10.0;
	vr->rot_ang = 2 * (M_PI / 180);
	vr->fov = 60 * (M_PI / 180);
	vr->raywth = 1;
	vr->rays = 0;
	vr->rx = 0;
	vr->ry = 0;
	vr->distance = 0;
	vr->upray = 0;
	vr->downray = 0;
	vr->rightray = 0;
	vr->leftray = 0;
	vr->hx = 0;
	vr->hy = 0;
	vr->vx = 0;
	vr->vy = 0;
	vr->vwall = 0;
	vr->hwall = 0;
	vr->xjump = 0;
	vr->yjump = 0;
}

void	init_vr(t_vars *vr)
{
	vr->no = 0;
	vr->so = 0;
	vr->we = 0;
	vr->ea = 0;
	vr->f = 0;
	vr->c = 0;
	vr->map = 0;
	vr->fd = 0;
	vr->fline = 0;
	vr->wsize = 0;
	vr->hsize = 0;
	vr->ywin = 0;
	vr->xwin = 0;
	vr->mlx = 0;
	vr->mlx_win = 0;
	vr->x = 0;
	vr->y = 0;
	vr->s = 0;
	vr->sy = 0;
	vr->px = 0;
	vr->py = 0;
	vr->dx = 0;
	vr->dy = 0;
	init_vr1(vr);
	init_vr2(vr);
}
