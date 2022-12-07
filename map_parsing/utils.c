/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:59:33 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/12 19:10:31 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	edit_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ' ' && count == 0
			&& ((i > 0 && str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (i > 0 && str[i - 1] && str[i - 1] >= 'A'
					&& str[i - 1] <= 'Z')))
			count++;
		else if (str[i] == ' ' && count && str[i - 1])
			str[i] = -1;
		i++;
	}
}

int	with_out_space(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] != -1)
			count++;
		i++;
	}
	return (count);
}

char	*no_spaces(char *str)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	len = with_out_space(str);
	s = malloc(len + 1);
	len = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != -1)
		{
			s[len] = str[i];
			len++;
		}
		i++;
	}
	s[len] = '\0';
	free(str);
	return (s);
}

int	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		else if ((str[i] < '0' || str[i] > '9')
			&& str[i] != ',' && str[i] != ' ')
		{
			printf("Error : Special character in your map plz fix it.");
			return (0);
		}
		i++;
	}
	if (count > 2)
	{
		printf("Error : There is a problem with comma\n");
		return (0);
	}
	return (1);
}
