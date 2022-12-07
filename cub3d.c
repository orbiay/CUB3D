/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:58:49 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 17:35:30 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_p_angle(t_vars *vr)
{
	int	i;
	int	j;

	i = 0;
	while (vr && vr->map && vr->map[i] != 0 && !vr->p_angle)
	{
		j = 0;
		while (vr->map[i][j] != '\0' && !vr->p_angle)
		{
			if (vr->map[i][j] == 'N')
				vr->p_angle = 3 * (M_PI / 2);
			else if (vr->map[i][j] == 'W')
				vr->p_angle = M_PI ;
			else if (vr->map[i][j] == 'S')
				vr->p_angle = M_PI / 2;
			else if (vr->map[i][j] == 'E')
				vr->p_angle = 2 * M_PI;
			j++;
		}
		i++;
	}
}

void	copy_all_map(t_vars *vr)
{
	vr->no = ft_strdup(vr->all_maps.no);
	vr->so = ft_strdup(vr->all_maps.so);
	vr->ea = ft_strdup(vr->all_maps.ea);
	vr->we = ft_strdup(vr->all_maps.we);
	vr->map = ft_split(vr->all_maps.full_map, '\n');
	vr->f = ft_strdup(vr->all_maps.f);
	vr->c = ft_strdup(vr->all_maps.c);
	vr->all_maps.color_c = rgb_to_hexa(vr->c);
	vr->all_maps.color_f = rgb_to_hexa(vr->f);
}

int	main(int ac, char **av)
{
	t_vars	vr;

	if (ac == 2)
	{
		init_vr(&vr);
		vr.all_maps = read_and_add(av);
		copy_all_map(&vr);
		init_p_angle(&vr);
		get_winsize(&vr);
	}
}
