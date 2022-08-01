/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:34 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 10:50:57 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_data(t_map **map, char **spltd)
{
	if (ft_strcmp(spltd[0], "NO") == 0 && !((*map)->element.no))
	{
		(*map)->element.no = spltd;
	}
	else if (ft_strcmp(spltd[0], "SO") == 0 && !((*map)->element.so))
		(*map)->element.so = spltd;
	else if (ft_strcmp(spltd[0], "WE") == 0 && !((*map)->element.we))
		(*map)->element.we = spltd;
	else if (ft_strcmp(spltd[0], "EA") == 0 && (!(*map)->element.ea))
		(*map)->element.ea = spltd;
	else
	{
		if (spltd[0][0] == 'F' && !(*map)->element.f && !check_color(spltd))
			(*map)->element.f = spltd;
		else if (spltd[0][0] == 'C'
			&& !(*map)->element.c && !check_color(spltd))
			(*map)->element.c = spltd;
		else
		{
			printf ("Error double config");
			exit(1);
		}
	}
}

int	check_line(char *line, t_map **map)
{
	int		j;
	char	**spltd;

	if (ft_strchr(line, ' '))
	{
		spltd = ft_split(line, ' ');
		j = ft_size(spltd);
		if ((ft_strcmp(spltd[0], "NO") == 0 || ft_strcmp(spltd[0], "SO") == 0
				|| ft_strcmp(spltd[0], "WE") == 0
				|| ft_strcmp(spltd[0], "EA") == 0
				|| (check_fc(spltd[0]))) && (j == 2))
		{
			assign_data(map, spltd);
			return (1);
		}
	}
	return (0);
}

int	checkline(char *line, t_map **map)
{
	if (check_line(line, map))
		return (1);
	else
		handle_err(1, *map);
	return (0);
}

char	*parsing(char *line, int fd, t_map *map, char *str)
{
	int	count;

	count = 0;
	while (line)
	{
		while (line[0] == '\n' && count != 7)
		{
			free(line);
			line = get_next_line(fd);
		}
		if (count == 6)
			count++;
		if (ft_strchr(line, ' ') && count < 6)
			count += checkline(line, &map);
		else if (count < 6)
			handle_err(2, map);
		if (count == 7)
			str = free_previous_str(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

int	read_map(char *file, t_map *map)
{
	char	*line;
	int		fd;
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	initialize_map(map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_err(0, map);
	line = get_next_line(fd);
	str = parsing(line, fd, map, str);
	if (!check_map(map, str))
		return (0);
	return (1);
}
