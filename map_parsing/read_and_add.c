/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:50:21 by orbiay            #+#    #+#             */
/*   Updated: 2022/11/14 15:32:01 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*only_map(char *str)
{
	char	**sp_str;
	char	*ret_str;
	int		i;
	int		count;

	i = 6;
	ret_str = NULL;
	sp_str = NULL;
	sp_str = ft_split(str, '\n');
	count = counting(sp_str);
	while (i < count)
	{
		if (i > 6)
			ret_str = ft_strjoin(ret_str, "\n");
		ret_str = ft_strjoin(ret_str, sp_str[i]);
		i++;
	}
	ft_free(sp_str);
	return (ret_str);
}

void	fd_protection(int fd)
{
	if (fd == -1)
	{
		perror("Error ");
		exit (0);
	}
}

void	check_new_line2(char *str, int *i, int *count)
{
	(*i) = 0;
	while (str[(*i)])
	{
		if ((*i) > 0 && ((str[(*i) - 1] == 'N' && str[(*i)] == 'O')
				|| (str[(*i) - 1] == 'S' && str[(*i)] == 'O')
				|| (str[(*i) - 1] == 'W' && str[(*i)] == 'E')
				|| (str[(*i) - 1] == 'E' && str[(*i)] == 'A')
				|| (str[(*i)] == 'F') || (str[(*i)] == 'C')))
				(*count)++;
		else if ((*count) == 6 && str[(*i)] == '\n')
			return ;
			(*i)++;
	}
}

int	check_new_line(char *str)
{
	static int		j;
	static int		count;
	int				i;

	check_new_line2(str, &i, &count);
	if (count == 6)
	{
		while (str[i])
		{
			if (str[i] != '\n')
				break ;
			i++;
		}
		j += i;
		while (str[j])
		{
			if (str[j + 1] && (str[j] == '\n' && str[j + 1] == '\n'))
			{
				printf("Error: new line in ur map");
				return (0);
			}
			j++;
		}
	}
	return (1);
}

char	*read_file(int fd)
{
	char	*buf;
	char	*str;
	int		count;

	count = 0;
	buf = get_next_line(fd);
	str = NULL;
	while (buf)
	{
		str = ft_strjoin(str, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	if (!check_new_line(str))
	{
		free(str);
		exit(1);
	}
	return (str);
}
// int main (int	ac, char	**av)
// {
// 	t_fd	f;
// 	(void)ac;
// 	f = read_and_add(av);
// }
