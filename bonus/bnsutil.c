/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnsutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:36:15 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/04 15:45:42 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_bns(t_map *map)
{
	map->utlbns.i = 0;
	map->utlbns.n = 0;
	map->utlbns.v = 0;
	map->ray_x = map->player_x;
	map->ray_y = map->player_y;
}

void	check_n(t_map *map, double ray_angle)
{
	if (map->utlbns.n)
	{
		map->ray_x += cos(to_radian(ray_angle)) / 566;
		map->utlbns.n = 0;
	}
	else
	{
		map->ray_y += sin(to_radian(ray_angle)) / 566;
		map->utlbns.n = 1;
	}
}

int	start_projection(t_map *map, double ray_angle, int *x)
{
	map->ray_x = map->player_x;
	map->ray_y = map->player_y;
	init_data_bns(map);
	while (ft_pos(map->buf[(int)floor(map->ray_y)][(int)floor(map->ray_x)]))
	{
		check_n(map, ray_angle);
		if (map->buf[(int)floor(map->ray_y)][(int)floor(map->ray_x)] == 'P')
		{
			if (sqrt(power(map->ray_x - map->player_x)
					+ power(map->ray_y - map->player_y)) > 1.2
				&& map->utlbns.v == 0)
			{
				*x = 1;
				break ;
			}
			else
				map->utlbns.v = 1;
		}
	}
	return (map->utlbns.n);
}

void	check_rayangle(t_map *map, double ray_angle, int n)
{
	if (cos(to_radian(ray_angle)) < 0 && n == 0)
		map->i = 2;
	else if (cos(to_radian(ray_angle)) > 0 && n == 0)
		map->i = 3;
	if (sin(to_radian(ray_angle)) < 0 && n == 1)
		map->i = 1;
	else if (sin(to_radian(ray_angle)) > 0 && n == 1)
		map->i = 0;
}

void	projection_draw(t_map *map)
{
	int	i;
	int	n;
	int	x;

	i = 0;
	n = 0;
	x = 0;
	while (i < map->width)
	{
		map->ray_x = map->player_x;
		map->ray_y = map->player_y;
		x = 0;
		n = start_projection(map, map->utlbns.ray_angle, &x);
		if (x == 1)
			map->i = 4;
		else
			check_rayangle(map, map->utlbns.ray_angle, n);
		map->dist = sqrt(power(map->ray_x - map->player_x)
				+ power(map->ray_y - map->player_y));
		map->dist = map->dist
			* cos(to_radian(map->utlbns.ray_angle - map->player_angle));
		draw3d(map, map->dist, i, n);
		map->utlbns.ray_angle += map->utlbns.incre;
		i++;
	}
}
