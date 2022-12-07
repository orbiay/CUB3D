/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:28:24 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/13 16:51:03 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	counting(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	len(char **str)
{
	int		i;
	int		j;
	int		sum;

	sum = 0;
	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		sum += j;
		i++;
	}
	return (sum);
}

void	joining2(char	**str, int count, int i, char	*re_str)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			re_str[k] = str[i][j];
			j++;
			k++;
		}
		if (count - 1 != 0)
		{
			re_str[k++] = ' ';
			count--;
		}
		i++;
	}
	re_str[k] = '\0';
}

char	*joining(char **str)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	*re_str;

	count = counting(str) - 1;
	k = 0;
	j = 0;
	i = 1;
	re_str = malloc(len(str) + 1 + count);
	joining2(str, count, i, re_str);
	return (re_str);
}

int	check_c(char	**str)
{
	if (str[0] && !ft_strcmp(str[0], "C") && counting(str) == 2)
		return (1);
	return (0);
}
