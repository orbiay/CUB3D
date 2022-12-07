/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:45:57 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:49:37 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_vars *vr, int color)
{
	int	i;
	int	j;

	j = 0;
	vr->y = vr->sy;
	while (j < 50 && vr->y < vr->ywin)
	{
		i = 0;
		vr->x = vr->s;
		while (i < 50 && vr->x < vr->xwin && vr->y < vr->ywin)
		{
			if ((vr->y == vr->sy || vr->x == vr->s)
				&& (color == 1 || color == 0))
				my_mlx_pixel_put(&(vr->img), vr->x, vr->y, 0x00000000);
			else if (color == 0)
				my_mlx_pixel_put(&(vr->img), vr->x, vr->y, 0x00414C6B);
			else if (color == 1)
				my_mlx_pixel_put(&(vr->img), vr->x, vr->y, 0x00E6E6FA);
			i++;
			vr->x++;
		}
		j++;
		vr->y++;
	}
}
