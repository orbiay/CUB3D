/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_point1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:33:40 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:06:44 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	v_point1(t_vars *vr, double deltax, double deltay)
{
	int		outwall;
	int		pixel;

	outwall = 1;
	vr->vx2 = vr->vx;
	vr->vy2 = vr->vy;
	if (vr->leftray)
		pixel = 1;
	else
		pixel = 0;
	while (outwall && vr->vx2 >= 0 && vr->vx2 <= vr->xwin
		&& vr->vy2 >= 0 && vr->vy2 <= vr->ywin)
	{
		outwall = outside_wall(vr->vx2 - pixel, vr->vy2, vr);
		if (!outwall)
			break ;
		vr->vx2 += deltax;
		vr->vy2 += deltay;
	}
	if (!outwall)
		vr->vwall = 1;
	else if (outwall)
		vr->vwall = 0;
}
