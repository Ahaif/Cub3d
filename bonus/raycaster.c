/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:28 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 09:32:16 by foulare          ###   ########.fr       */
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
	map->planx = 0;
	map->plany = 0.66;
	map->dirx = 0;
	map->diry = -1;
	map->img = mlx_new_image (map->mlx, map->width, map->heigth);
	map->img_buf = (unsigned int *)mlx_get_data_addr
		(map->img, &map->pix, &map->lin, &map->d);
}

void	assign_var(t_map *map)
{
	map->img_m = mlx_new_image (map->mlx, 300, 300);
	map->img_buf_m = (unsigned int *)mlx_get_data_addr
		(map->img_m, &map->pix, &map->lin, &map->d);
	map->sprite.x = map->player_x - 10;
	map->sprite.y = map->player_y - 10;
	map->sprite.end_x = map->player_x + 10;
	map->sprite.end_y = map->player_y + 10;
	if (map->sprite.x < 0)
		map->sprite.x = 0;
	if (map->sprite.end_x >= map->buf_w)
		map->sprite.end_x = map->buf_w - 1;
	if (map->sprite.y < 0)
		map->sprite.y = 0;
	if (map->sprite.end_y >= map->buf_h)
		map->sprite.end_y = map->buf_h - 1;
	map->sprite.stepx = (map->sprite.end_x - map->sprite.x) / 300.0;
	map->sprite.stepy = (map->sprite.end_y - map->sprite.y) / 300.0;
	map->sprite.oldy = 0;
}

void	drawmini(t_map *map)
{
	assign_var(map);
	while (map->sprite.oldy < 300)
	{
		map->sprite.oldx = 0;
		map->sprite.x = map->player_x - 10;
		if (map->sprite.x < 0)
		map->sprite.x = 0;
		while (map->sprite.oldx < 300)
		{
			if (map->buf[(int)map->sprite.y][(int)map->sprite.x] == '1')
				map->img_buf_m[map->sprite.oldy
					* 300 + map->sprite.oldx] = 25215;
			if ((int)map->player_x == (int)map->sprite.x
				&& (int)map->player_y == (int)map->sprite.y)
				map->img_buf_m[map->sprite.oldy
					* 300 + map->sprite.oldx] = 4000;
			if (map->buf[(int)map->sprite.y][(int)map->sprite.x] == 'P')
				map->img_buf_m[map->sprite.oldy
					* 300 + map->sprite.oldx] = 16776960;
			map->sprite.oldx++;
			map->sprite.x += map->sprite.stepx;
		}
		map->sprite.y += map->sprite.stepy;
		map->sprite.oldy++;
	}
}

int	raycaster(t_map *map)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	move(map);
	map->utlbns.incre = (double)map->fov / (double)map->width;
	map->utlbns.ray_angle = map->player_angle - (map->fov / 2);
	init_data(map);
	projection_draw(map);
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	i = map->m % 5;
	map->m++;
	if (map->m == 100000)
		map->m = 1;
	mlx_put_image_to_window(map->mlx, map->win, map->texp[i].img, map->width
		/ 1.3 - map->texp[i].width, map->heigth / 1.1 - map->texp[i].height);
	drawmini(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img_m, 10, 10);
	return (0);
}
