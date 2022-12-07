/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:27:09 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 18:04:09 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	colors(t_vars *data, t_data textures, int x, int y)
{
	char	*dst;

	dst = NULL;
	(void)data;
	if (data->verticalhit)
		x = (int)(data->ry) % textures.w;
	else
		x = (int)(data->rx) % textures.w;
	dst = textures.addr
		+ (y * textures.line_length + x * (textures.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
