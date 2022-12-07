/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anglehandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:37:49 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:26:57 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	anglehandler(double *r_angle)
{
	*r_angle = remainder(*r_angle, M_PI * 2);
	if (*r_angle < 0)
		*r_angle = (M_PI * 2) + *r_angle;
}
