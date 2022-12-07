/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:43:14 by ridrissi          #+#    #+#             */
/*   Updated: 2022/11/13 18:34:48 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wsize(char **map)
{
	int	i;
	int	wmax;

	i = 0;
	wmax = 0;
	while (map[i] != 0)
	{
		if (ft_strlen(map[i]) > wmax)
		{
			wmax = ft_strlen(map[i]);
		}
		i++;
	}
	return (wmax);
}
