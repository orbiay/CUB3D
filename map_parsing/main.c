/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:57:49 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/13 16:54:49 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_f_c(char	**str,	int line)
{
	static int	f;
	static int	c;

	if (check_f(str))
		f++;
	else if (check_c(str))
		c++;
	else if (f > 1 || c > 1)
	{
		printf("Error Map : Duplicate.");
		return (0);
	}
	if (line == 5 && (c == 0 || f == 0))
	{
		printf("Error : Problem in Color .");
		return (0);
	}
	return (1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_textures2(char **str)
{
	if (str[0] && ft_strcmp(str[0], "NO") && ft_strcmp(str[0], "SO")
		&& ft_strcmp(str[0], "WE") && ft_strcmp(str[0], "EA")
		&& ft_strcmp(str[0], "F") && ft_strcmp(str[0], "C"))
	{
		printf("Error : Textures or Colors undefined.");
		return (0);
	}
	return (1);
}

int	check_textures(char **str,	int line)
{
	static int	no;
	static int	so;
	static int	we;
	static int	ea;

	if (check_no(str))
		no++;
	else if (check_so(str))
		so++;
	else if (check_we(str))
		we++;
	else if (check_ea(str))
		ea++;
	else if (no > 1 || so > 1 || we > 1 || ea > 1)
	{
		printf("Error Map : Duplicate.");
		return (0);
	}
	else if (line == 5 && (no == 0 || so == 0 || we == 0 || ea == 0))
	{
		printf("Error Map : Something Wrong with Textures.");
		return (0);
	}
	return (check_f_c(str, line));
}

int	first_forth_lines(char *split_str,	int line)
{
	char	*str;
	char	**split;

	str = ft_strdup(split_str);
	split = ft_split(str, ' ');
	if (!check_textures2(split))
	{
		ft_free(split);
		free(str);
		return (0);
	}
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
