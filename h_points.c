/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_points.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:35:38 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 18:38:57 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	h_points(t_vars *vr, double deltax, double deltay)
{
	int		outwall;
	int		pixel;

	outwall = 1;
	vr->hx1 = vr->hx;
	vr->hy1 = vr->hy;
	if (vr->upray)
		pixel = 1;
	else
		pixel = 0;
	while (outwall && vr->hx1 >= 0 && vr->hx1 <= vr->xwin
		&& vr->hy1 >= 0 && vr->hy1 <= vr->ywin)
	{
		outwall = outside_wall(vr->hx1, vr->hy1 - pixel, vr);
		if (!outwall)
			break ;
		vr->hx1 += deltax;
		vr->hy1 += deltay;
	}
	if (!outwall)
		vr->hwall = 1;
	else if (outwall)
		vr->hwall = 0;
}
