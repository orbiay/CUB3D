/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:31:20 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:29:04 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast(t_vars *vr, double r_angle)
{
	double	deltax;
	double	deltay;

	deltax = 0;
	deltay = 0;
	anglehandler(&r_angle);
	init_raydir(r_angle, vr);
	vr->hy = floor(vr->py / 50) * 50;
	if (vr->downray)
		vr->hy += 50;
	vr->hx = vr->px + ((vr->hy - vr->py) / tan(r_angle));
	deltay = 50;
	if (vr->upray)
		deltay *= -1;
	deltax = 50 / tan(r_angle);
	if (vr->leftray && deltax > 0)
		deltax *= -1;
	if (vr->rightray && deltax < 0)
		deltax *= -1;
	h_points(vr, deltax, deltay);
	v_points(vr, r_angle);
}
