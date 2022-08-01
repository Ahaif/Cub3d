/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:28 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 12:59:49 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3d(t_map *map, double dist, int x, int n)
{
	int		start;
	double	dis;
	double	texpos;
	int		i;

	map->treed.wall_h = floor((double)(map->heigth / 3)
			/ (double)dist);
	start = floor(-map->treed.wall_h / 2 + map->heigth / 2);
	i = 0;
	if (start < 0)
		start = 0;
	if (n)
		dis = (map->player_x + map->ray_x) - (int)(map->player_x + map->ray_x);
	if (n == 0)
		dis = (map->player_y + map->ray_y) - (int)(map->player_y + map->ray_y);
	map->treed.xtex = dis * map->tex[map->i].width;
	map->treed.step = 1.0 * (double)map->tex[map->i].height / map->treed.wall_h;
	if (map->treed.wall_h < map->heigth)
		texpos = 0.0;
	else
		texpos = (map->treed.wall_h / 2 - map->heigth / 2) * map->treed.step;
	draw_floor(map, i, start, x);
	start = draw_walls(map, start, texpos, x);
	draw_cel(map, start, x);
}

void	init_data(t_map *map)
{
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	map->planx = 0;
	map->plany = 0.66;
	map->dirx = 0;
	map->diry = -1;
	map->img = mlx_new_image (map->mlx, map->width, map->heigth);
	map->img_buf = (unsigned int *)mlx_get_data_addr
		(map->img, &map->pix, &map->lin, &map->d);
}

int	start_projection(t_map *map, double ray_angle)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < map->width)
	{
		map->ray_x = map->player_x;
		map->ray_y = map->player_y;
		while (ft_pos(map->buf[(int)map->ray_y][(int)map->ray_x]))
		{
			if (n)
			{
				map->ray_x += cos(to_radian(ray_angle)) / 566;
				n = 0;
			}
			else
			{
				map->ray_y += sin(to_radian(ray_angle)) / 566;
				n = 1;
			}
			i++;
		}
	}
	return (n);
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

int	raycaster(t_map *map)
{
	double	ray_angle;
	int		i;
	int		n;
	double	incre;

	n = 0;
	i = 0;
	move(map);
	init_data(map);
	incre = (double)map->fov / (double)map->width;
	ray_angle = map->player_angle - (map->fov / 2);
	while (i++ < map->width)
	{
		n = start_projection(map, ray_angle);
		check_rayangle(map, ray_angle, n);
		map->dist = sqrt(power(map->ray_x - map->player_x)
				+ power(map->ray_y - map->player_y));
		map->dist = map->dist * cos(to_radian(ray_angle - map->player_angle));
		draw3d(map, map->dist, i, n);
		ray_angle += incre;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	return (0);
}
