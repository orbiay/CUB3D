/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:21:30 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/14 15:25:10 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_to_image(t_vars *vr, t_address *data)
{
	data->no.img = mlx_xpm_file_to_image(vr->mlx,
			vr->no, &data->no.w, &data->no.h);
	data->so.img = mlx_xpm_file_to_image(vr->mlx,
			vr->so, &data->so.w, &data->so.h);
	data->we.img = mlx_xpm_file_to_image(vr->mlx,
			vr->we, &data->we.w, &data->we.h);
	data->ea.img = mlx_xpm_file_to_image(vr->mlx,
			vr->ea, &data->ea.w, &data->ea.h);
	if (!data->no.img || !data->so.img || !data->we.img || !data->ea.img)
	{
		printf("Error : textures");
		exit(0);
	}
	data->no.addr = mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel,
			&data->no.line_length, &data->no.endian);
	data->so.addr = mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel,
			&data->so.line_length, &data->so.endian);
	data->we.addr = mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel,
			&data->we.line_length, &data->we.endian);
	data->ea.addr = mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel,
			&data->ea.line_length, &data->ea.endian);
}
