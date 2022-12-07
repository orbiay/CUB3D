/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:31:35 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/13 14:32:09 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

t_fd	checkingmap(char *str)
{
	t_fd	fd2;

	if (map_checking(str))
	{
		fd2 = take_path(str);
		if (!map_checking2(str) || !check_colors_valid(fd2.f, fd2.c))
		{
			free(str);
			exit(1);
		}
		printf("\nYour map\n");
		free(str);
	}
	else
	{
		free(str);
		exit(1);
	}
	return (fd2);
}

t_fd	read_and_add(char **av)
{
	int		fd;
	char	*str;
	int		count;
	t_fd	fd2;	

	fd = open(av[1], O_RDONLY);
	check_extension(av);
	fd_protection(fd);
	fd2.full_map = NULL;
	count = 0;
	str = NULL;
	str = read_file(fd);
	if (!str)
	{
		printf("Error : Map invalid");
		exit(1);
	}
	fd2 = checkingmap(str);
	return (fd2);
}
