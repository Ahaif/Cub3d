/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:50:25 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 12:41:35 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	to_radian(double angle)
{
	return (angle * PI / 180);
}

double	power(double x)
{
	return (x * x);
}

void	draw_floor(t_map *map, int i, int start, int x)
{
	while (i < start)
	{
		if (i * map->width + x >= map->heigth * map->width)
			break ;
		map->img_buf[i * map->width + x] = map->color_f;
		i++;
	}
}

int	draw_walls(t_map *map, int start, double texpos, int x)
{
	int	end;

	end = map->treed.wall_h / 2 + map->heigth / 2;
	if (end >= map->heigth)
		end = map->heigth - 1;
	while (start < end)
	{
		map->treed.texy = (int)texpos & (map->tex[map->i].height - 1);
		texpos += map->treed.step;
		if (start * map->width + x >= map->heigth * map->width)
			break ;
		map->img_buf[start * map->width + x]
			= (unsigned int)map->tex[map->i].addr[map->treed.texy
			* map->tex[map->i].width + (int)map->treed.xtex];
		start++;
	}
	return (start);
}

void	draw_cel(t_map *map, int start, int x)
{
	while (start < map->heigth)
	{
		if (start * map->width + x >= map->heigth
			* map->width || start * map->width + x < 0)
			break ;
		map->img_buf[start * map->width + x] = map->color_c;
		start++;
	}
}
