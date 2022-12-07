/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_points.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:32:21 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:08:18 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	v_points(t_vars *vr, double r_angle)
{
	double	deltax;
	double	deltay;

	deltax = 0;
	deltay = 0;
	vr->vx = floor(vr->px / 50) * 50;
	if (vr->rightray)
		vr->vx += 50;
	vr->vy = vr->py + ((vr->vx - vr->px) * tan(r_angle));
	deltax = 50;
	if (vr->leftray)
		deltax *= -1;
	deltay = 50 * tan(r_angle);
	if (vr->upray && deltay > 0)
		deltay *= -1;
	if (vr->downray && deltay < 0)
		deltay *= -1;
	v_point1(vr, deltax, deltay);
}
