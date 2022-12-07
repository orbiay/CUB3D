/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:29:14 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/15 13:21:49 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_distance(t_vars *vr, double dst, int i)
{
	vr->rw_distance = dst;
	vr->verticalhit = i;
}

void	dstcmp(t_vars *vr)
{
	double	dist_pv;
	double	dist_ph;

	dist_pv = 0;
	dist_ph = 0;
	if (vr->vwall)
		dist_pv = sqrt((pow(vr->vx2 - vr->px, 2) + pow(vr->vy2 - vr->py, 2)));
	else if (!vr->vwall)
		dist_pv = 2147483647;
	if (vr->hwall)
		dist_ph = sqrt((pow(vr->hx1 - vr->px, 2) + pow(vr->hy1 - vr->py, 2)));
	else if (!vr->hwall)
		dist_ph = 2147483647;
	if (dist_pv < dist_ph)
	{
		vr->rx = vr->vx2;
		vr->ry = vr->vy2;
		set_distance(vr, dist_pv, 1);
	}
	else
	{
		vr->rx = vr->hx1;
		vr->ry = vr->hy1;
		set_distance(vr, dist_ph, 0);
	}
}
