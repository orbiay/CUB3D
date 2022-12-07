/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:38:51 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/13 14:27:23 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	req_zero(char **str, int start, int i)
{
	int	count;

	count = 0;
	if (!str[start + 1])
		count++;
	if (!req_zero2(str, start, i))
		return (0);
	if ((!str[start + 1][i]) || (str[start + 1][i] && str[start + 1][i] != '0'
		&& !check_player(str[start + 1][i]) && str[start + 1][i] != '1'))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	if ((!str[start - 1][i]) || (str[start - 1][i] && str[start - 1][i] != '0'
		&& !check_player(str[start - 1][i]) && str[start - 1][i] != '1'))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	return (1);
}

int	check_pos_player(char **str, int i, int j)
{
	if (!str[i + 1][j] || (str[i + 1][j] && str[i + 1][j] == ' '))
	{
		printf("Error : Problem under Player [%d][%d].\n", i + 1, j);
		return (0);
	}
	else if (!str[i - 1][j] || (str[i - 1][j] && str[i - 1][j] == ' '))
	{
		printf("Error : Problem above Player [%d][%d].\n", i - 1, j);
		return (0);
	}
	else if (!str[i][j + 1] || (str[i + 1][j] && str[i + 1][j] == ' '))
	{
		printf("Error : Problem left Player [%d][%d].\n", i, j + 1);
		return (0);
	}
	else if (!str[i][j - 1] || (str[i][j - 1] && str[i][j - 1] == ' '))
	{
		printf("Error : Problem above Player [%d][%d].\n", i, j - 1);
		return (0);
	}
	return (1);
}

int	check_p(char **str, int *cout_p, int *i)
{
	int	j;

	while (str[(*i)])
	{
		j = 0;
		while (str[*i][j])
		{
			if (check_player(str[(*i)][j]))
			{
				if (!check_pos_player(str, (*i), j))
					return (0);
				(*cout_p)++;
			}
			j++;
		}
		(*i)++;
	}
	return (1);
}

int	last_touches(char	**str)
{
	int		cout_p;
	int		i;
	int		j;

	j = 0;
	i = 6;
	cout_p = 0;
	if (!check_p(str, &cout_p, &i))
		return (0);
	if (!last_touches2(cout_p, i))
		return (0);
	return (1);
}

int	check_colors_valid(char *F, char *C)
{
	char	**sp_f;
	char	**sp_c;

	sp_c = ft_split(C, ',');
	sp_f = ft_split(F, ',');
	if (!check_colors_valid2(sp_f, sp_c))
		return (0);
	if (!check_isdigit(sp_f) || !check_isdigit(sp_c))
	{
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}
	if (!check_comma(F) || !check_comma(C))
	{
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}
	ft_free(sp_f);
	ft_free(sp_c);
	return (1);
}
