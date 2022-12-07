/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_playerp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:42:13 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 18:32:36 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_playerp(t_vars *vr)
{
	int	i;
	int	j;

	i = 0;
	vr->py = 0;
	while (vr && vr->map && vr->map[i] != 0)
	{
		j = 0;
		vr->px = 0;
		vr->py += 50;
		while (vr->map[i][j] != '\0')
		{
			vr->px += 50;
			if (vr->map[i][j] == 'N' || vr->map[i][j] == 'W'
			|| vr->map[i][j] == 'E' || vr->map[i][j] == 'S')
			{	
				vr->py -= 30;
				vr->px -= 25;
				return ;
			}
			j++;
		}
		i++;
	}
}
