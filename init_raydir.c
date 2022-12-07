/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raydir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 18:39:27 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raydir(double r_angle, t_vars *vr)
{
	if (r_angle > 0 && r_angle < M_PI)
	{
		vr->downray = 1;
		vr->upray = 0;
	}
	else if (!(r_angle > 0 && r_angle < M_PI))
	{
		vr->downray = 0;
		vr->upray = 1;
	}
	if (r_angle < (0.5 * M_PI) || r_angle > (1.5 * M_PI))
	{
		vr->rightray = 1;
		vr->leftray = 0;
	}
	else if (!(r_angle < (0.5 * M_PI) || r_angle > (1.5 * M_PI)))
	{
		vr->rightray = 0;
		vr->leftray = 1;
	}
}
