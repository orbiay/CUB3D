/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:40:53 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:46:01 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_vars *vr)
{
	int	x1;
	int	y;
	int	i;

	i = 0;
	get_playerp(vr);
	x1 = vr->px;
	y = vr->py;
	while (i < 10)
	{
		my_mlx_pixel_put(&(vr->img), vr->px, y, 0x00000000);
		my_mlx_pixel_put(&(vr->img), x1, vr->py, 0x00000000);
		x1--;
		y++;
		i++;
	}
}
