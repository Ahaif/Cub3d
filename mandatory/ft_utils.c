/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <foulare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:28:28 by foulare           #+#    #+#             */
/*   Updated: 2022/06/11 15:12:13 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				p;

	i = 0;
	p = 0;
	while ((s1[i] || s2[i]) && p == 0)
	{
		if (s1[i] != s2[i])
			p = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (p);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	n;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * n);
}

int	ft_close(t_map *map)
{
	free_window(map);
	free_map(map);
	system("leaks cub3D");
	exit(0);
	return (0);
}

int	convert_rgb(char *str)
{
	char	**split;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	split = ft_split(str, ',');
	while (split[i])
	{
		if (i == 0)
			ret = ft_atoi(split[i]);
		else
			ret = (ret << 8) + ft_atoi(split[i]);
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (ret);
}
