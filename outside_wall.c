/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:38:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:03:49 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	outside_wall(double x, double y, t_vars *vr)
{
	int	mapx;
	int	mapy;

	mapx = 0;
	mapy = 0;
	if (x < 0 || x > vr->xwin || y < 0 || y > vr->ywin)
		return (0);
	mapx = x / 50;
	mapy = y / 50;
	if (vr && vr->map && mapx >= 0
		&& mapx < ft_strlen(vr->map[mapy]) && vr->map[mapy][mapx] != '1')
		return (1);
	return (0);
}
