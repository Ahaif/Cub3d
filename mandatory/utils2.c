/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <foulare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:59:45 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/11 14:58:10 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_concat(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}

void	init_tex(t_map *map)
{
	int	j;

	j = -1;
	while (++ j < 4)
	{
		map->tex[j].img = 0;
		map->tex[j].addr = 0;
		map->tex[j].height = 0;
		map->tex[j].width = 0;
	}
}

void	initialize_map(t_map *map)
{
	map->element.no = 0;
	map->element.ea = 0;
	map->element.so = 0;
	map->element.we = 0;
	map->element.f = 0;
	map->element.c = 0;
	map->heigth = 0;
	map->width = 0;
	map->player_x = 0;
	map->player_y = 0;
}

int	check_color(char **str)
{
	char	**s;
	int		i;
	int		y;
	int		n;

	s = ft_split(str[1], ',');
	i = -1;
	n = 0;
	while (s[++i])
	{
		y = -1;
		if (ft_atoi(s[i]) < 0 || ft_atoi(s[i]) > 255 || s[i][0] == '\n')
			n = 1;
		while (s[i][++y])
			if ((s[i][y] < '0' || s[i][y] > '9') && s[i][y] != '\n')
				n = 1;
	}
	free_str(s);
	if (i != 3)
		n = 1;
	return (n);
}
