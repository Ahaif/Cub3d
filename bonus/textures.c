/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:10 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 10:44:58 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_window_tex(t_map *map)
{
	int	i;

	i = -1;
	printf("Error\nTexture file failed to open\nRetry\n");
	while (++i < 4)
		if (map->tex[i].img)
			mlx_destroy_image(map->mlx, map->tex[i].img);
	free(map->mlx);
	exit(1);
	return (0);
}

char	*rem_bs(char *str)
{
	int		i;
	char	*new;

	i = str_len(str);
	new = malloc(sizeof(char) * i);
	if (!new)
		exit(0);
	i--;
	new[i] = 0;
	while (--i >= 0)
	{
		new[i] = str[i];
	}
	return (new);
}

char	*free_previous_str(char *str, char *line)
{
	char	*temp;

	temp = ft_concat(str, line);
	free(str);
	str = temp;
	return (str);
}
