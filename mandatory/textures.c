/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:10 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 10:50:34 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_window_tex(t_map *map, char **str)
{
	int	i;

	i = -1;
	printf("Error\nTexture file failed to open\nRetry\n");
	free_str(str);
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
		exit(1);
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

int	add_text_img(t_map *map)
{
	char	**p;
	int		i;

	i = 0;
	p = malloc(sizeof(char *) * 5);
	p[0] = rem_bs(map->element.no[1]);
	p[1] = rem_bs(map->element.so[1]);
	p[2] = rem_bs(map->element.we[1]);
	p[3] = rem_bs(map->element.ea[1]);
	p[4] = NULL;
	while (i < 4)
	{
		map->tex[i].img = mlx_xpm_file_to_image
			(map->mlx, p[i], &map->tex[i].width, &map->tex[i].height);
		if (!map->tex[i].img)
			return (free_window_tex(map, p));
		map->tex[i].addr = (int *)mlx_get_data_addr
			(map->tex[i].img, &map->tex[i].bits_per_pixel,
				&map->tex[i].line_length, &map->tex[i].endian);
		if (!map->tex[i].addr)
			return (free_window_tex(map, p));
		i++;
	}
	free_str(p);
	return (1);
}
