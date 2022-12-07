/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:05:11 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/12 16:18:54 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_colors_valid2(char **sp_f, char **sp_c)
{
	if (!sp_f || !sp_c)
	{
		return (0);
	}
	if (counting(sp_f) != 3 || counting(sp_c) != 3)
	{
		printf("Error : There is problem in COLORS.");
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}
	return (1);
}

int	last_touches2(int cout_p, int i)
{
	if ((cout_p == 0 || cout_p > 1) || i == 6)
	{
		printf("Error : There is a problem with player");
		return (0);
	}
	return (1);
}

int	req_zero2(char **str, int start, int i)
{
	if (str[start][i + 1] && str[start][i + 1] != '0'
		&& !check_player(str[start][i + 1]) && str[start][i + 1] != '1')
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	if (str[start][i - 1] && str[start][i - 1] != '0'
		&& str[start][i - 1] != '1' && !check_player(str[start][i - 1]))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	return (1);
}

int	check_player(char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (1);
	return (0);
}
