/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:44:38 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:45:05 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_vars *vr)
{
	int	i;
	int	j;

	i = 0;
	vr->sy = 0;
	while (vr->map[i] != 0)
	{	
		vr->s = 0;
		j = 0;
		while (vr->map[i][j] != '\0')
		{
			if (vr->map[i][j] == '1')
				draw_square(vr, 0);
			else if (vr->map[i][j] != ' ')
				draw_square(vr, 1);
			j++;
			vr->s += 50;
		}
		vr->sy += 50;
		i++;
	}
}
