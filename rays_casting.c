/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:15 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/22 18:43:52 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_casting(t_vars *vr)
{
	int			i;
	double		r_angle;
	double		distance;
	t_address	data;

	i = 0;
	r_angle = vr->p_angle - (vr->fov / 2);
	file_to_image(vr, &data);
	while (i < vr->rays)
	{
		cast(vr, r_angle);
		dstcmp(vr);
		distance = vr->rw_distance * cos(r_angle - vr->p_angle);
		vr->wallheight_hold = (50 / distance) * vr->player_pplan;
		if (vr->wallheight_hold > vr->ywin)
			vr->wallheight = vr->ywin;
		else
			vr->wallheight = vr->wallheight_hold;
		draw_verticaline(i, ((vr->ywin / 2) - (vr->wallheight / 2)), vr, data);
		r_angle += vr->fov / vr->rays;
		i++;
	}
}
