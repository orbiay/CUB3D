/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/12 19:10:54 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	map_checking(char *str)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = ft_split(str, '\n');
	while (i < 6)
	{
		if (i < 4 && !first_forth_lines(split_str[i], i))
		{
			ft_free(split_str);
			return (0);
		}
		else if (i >= 4 && i < 6 && !two_lines_color(split_str[i], i))
		{
			ft_free(split_str);
			return (0);
		}
		i++;
	}
	ft_free(split_str);
	return (1);
}

int	check_spaces(char **str, int start)
{
	int		j;
	int		count;

	count = counting(str);
	if (!count)
		return (0);
	j = 0;
	while (str[start])
	{
		j = 0;
		if (!check_walls(str[start], start, count))
			return (0);
		while (str[start][j])
		{
			if (str[start][j] == '0' && !req_zero(str, start, j))
				return (0);
			j++;
		}
		start++;
	}
	return (1);
}

int	two_lines_color(char *split_str, int line)
{
	char	*str;
	char	**split;

	str = ft_strdup(split_str);
	edit_spaces(str);
	split = ft_split(str, ' ');
	split[1] = no_spaces(split[1]);
	if (!check_textures(split, line))
	{
		ft_free(split);
		free(str);
		return (0);
	}
	ft_free(split);
	free(str);
	return (1);
}
