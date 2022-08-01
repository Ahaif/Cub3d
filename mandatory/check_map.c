/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:55:20 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 09:27:28 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_error(t_map *map)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	y = 0;
	n = 0;
	while (map->buf[y])
	{
		x = 0;
		while (map->buf[y][x])
		{
			check_space(map, x, y);
			n += check_rest(map, x, y);
			x++;
		}
		y++;
	}
	if (n != 1)
		return (1);
	return (0);
}

char	*ft_duplic(char *str, int size)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	while (i < size)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

char	**getmap(char *str, int len, int nline)
{
	char	**buf;
	int		i;
	int		m;

	i = -1;
	m = 0;
	buf = malloc(sizeof(char *) * (nline + 1));
	if (!buf)
		return (NULL);
	while (++i < nline)
	{
		m = 0;
		while (*str && *str != '\n')
		{
			str++;
			m++;
		}
		buf[i] = ft_duplic(str - m, len);
		if (*str == '\n')
			str++;
	}
	buf[i] = NULL;
	return (buf);
}

int	maxlen(char *str, int *nline)
{
	int	i;
	int	ret;
	int	count;

	i = 0;
	ret = 0;
	*nline = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			count++;
		else if (str[i] == '\n' || str[i + 1] == '\0')
		{
			(*nline)++;
			if (count > ret)
				ret = count;
			count = 0;
		}
		i++;
	}
	return (ret);
}

int	check_map(t_map *map, char *str)
{
	int	len;
	int	nline;

	nline = 0;
	len = maxlen(str, &nline);
	map->heigth = 1000;
	map->width = 1000;
	map->buf = getmap(str, len, nline);
	free(str);
	if (find_error(map))
	{
		printf("Error in map\n");
		free(map);
		exit(1);
	}
	return (1);
}
