/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_verticaline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:25:06 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 19:02:44 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ve(double x, double y, t_vars	*vr, t_address	data)
{
	if (vr->verticalhit == 0 && vr->py > vr->ry)
		my_mlx_pixel_put(&(vr->img), x, y + vr->start, colors(vr, data.no,
				x, (int)((y + (vr->wallheight_hold - vr->wallheight) / 2)
					* (data.no.h / vr->wallheight_hold)) % data.no.h));
	else if (vr->verticalhit == 0 && vr->py < vr->ry)
		my_mlx_pixel_put(&(vr->img), x, y + vr->start, colors(vr, data.so,
				x, (int)((y + (vr->wallheight_hold - vr->wallheight) / 2)
					* (data.so.h / vr->wallheight_hold)) % data.so.h));
	else if (vr->verticalhit && vr->px > vr->rx)
		my_mlx_pixel_put(&(vr->img), x, y + vr->start, colors(vr, data.we,
				x, (int)((y + (vr->wallheight_hold - vr->wallheight) / 2)
					* (data.we.h / vr->wallheight_hold)) % data.we.h));
	else if (vr->verticalhit && vr->px < vr->rx)
		my_mlx_pixel_put(&(vr->img), x, y + vr->start, colors(vr, data.ea,
				x, (int)((y + (vr->wallheight_hold - vr->wallheight) / 2)
					* (data.ea.h / vr->wallheight_hold)) % data.ea.h));
}

void	draw_verticaline(double x, double y, t_vars	*vr, t_address data)
{
	int			f;
	int			c;

	y = 0;
	vr->start = (vr->ywin / 2) - vr->wallheight / 2;
	while (y < (vr->ywin / 2) + (vr->wallheight / 2) && y < vr->ywin)
	{
		draw_ve(x, y, vr, data);
		y++;
	}
	f = 0;
	while (f < vr->start)
	{
		my_mlx_pixel_put(&(vr->img), x, f, vr->all_maps.color_c);
		f++;
	}
	c = vr->ywin / 2 + vr->wallheight / 2;
	while (c < vr->ywin)
	{
		my_mlx_pixel_put(&(vr->img), x, c, vr->all_maps.color_f);
		c++;
	}
}
