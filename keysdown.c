/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keysdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:18:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 18:40:44 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keysdown(int keycode, t_vars *vr)
{
	if (keycode == 123)
		vr->move_rotation = -1;
	else if (keycode == 124)
		vr->move_rotation = 1;
	else if (keycode == 13)
		vr->move_directiony = 1;
	else if (keycode == 1)
		vr->move_directiony = -1;
	else if (keycode == 2)
		vr->move_directionx = 1;
	else if (keycode == 0)
		vr->move_directionx = -1;
	else if (keycode == 53)
		exit(0);
	return (0);
}
