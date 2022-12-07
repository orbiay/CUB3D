/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:49 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/12 22:13:09 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	map_checking2(char	*str)
{
	char	**split_str;
	int		statrt;

	statrt = 6;
	split_str = ft_split(str, '\n');
	if (!check_spaces(split_str, statrt))
	{
		ft_free(split_str);
		return (0);
	}
	if (!last_touches(split_str))
	{
		ft_free(split_str);
		return (0);
	}
	ft_free(split_str);
	return (1);
}

t_fd	file_dis(char *sp, char *s)
{
	t_fd	fd;

	fd.full_map = NULL;
	if (!ft_strcmp(sp, "NO"))
		fd.no = ft_strdup(s);
	else if (!ft_strcmp(sp, "SO"))
		fd.so = ft_strdup(s);
	else if (!ft_strcmp(sp, "WE"))
		fd.we = ft_strdup(s);
	else if (!ft_strcmp(sp, "EA"))
		fd.ea = ft_strdup(s);
	else if (!ft_strcmp(sp, "F"))
		fd.f = ft_strdup(s);
	else if (!ft_strcmp(sp, "C"))
		fd.c = ft_strdup(s);
	return (fd);
}

t_fd	take_path(char	*str)
{
	char	**str_sp;
	char	**sp;
	char	*s;
	t_fd	fd;
	int		i;

	i = 0;
	s = NULL;
	str_sp = ft_split(str, '\n');
	while (i < 6)
	{
		sp = ft_split(str_sp[i], ' ');
		if (counting(sp) > 2)
		{
			printf("Error : Textres or color with spaces invalid");
			ft_free(sp);
			exit(1);
		}
		fd = file_dis(sp[0], sp[1]);
		ft_free(sp);
		i++;
	}
	fd.full_map = only_map(str);
	ft_free(str_sp);
	return (fd);
}

int	check_isdigit(char **sp)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (sp[i])
	{
		j = 0;
		num = ft_atoi(sp[i]);
		if (num > 255 || num < 0)
		{
			printf("Error :Colors  %s High or low Than 255\n", sp[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_extension(char *av[])
{
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
	{
		printf("Provide a .cub file\n");
		exit(1);
	}
}
