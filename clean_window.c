/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:24:03 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:29:34 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_window(t_vars *vr)
{
	int	i;
	int	y;

	y = 0;
	while (y < vr->ywin)
	{
		i = 0;
		while (i < vr->xwin)
		{
			my_mlx_pixel_put(&(vr->img), i, y, 0x00000000);
			i++;
		}
		y++;
	}
}
