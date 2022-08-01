/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:10:07 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 12:42:22 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_map *map)
{
	double	x;
	double	y;
	double	angle;

	if (map->key.d == 1 || map->key.a == 1)
		angle = map->player_angle - 90;
	else
		angle = map->player_angle;
	x = cos(to_radian(angle)) * 0.1;
	y = sin(to_radian(angle)) * 0.1;
	if (map->key.l == 1)
		move_left(map);
	if (map->key.r == 1)
		move_right(map);
	else if ((map->key.w == 1 || map->key.a == 1)
		&& ft_pos(map->buf[(int)floor
				(map->player_y + y)][(int)floor(map->player_x + x)]))
		move_backforth(map, x, y);
	else if ((map->key.d == 1 || map->key.s == 1)
		&& ft_pos(map->buf[(int)floor
				(map->player_y - y)][(int)floor(map->player_x - x)]))
		rotateangle(map, x, y);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == A_KEY)
		map->key.a = 1;
	if (keycode == D_KEY)
		map->key.d = 1;
	if (keycode == S_KEY)
		map->key.s = 1;
	if (keycode == W_KEY)
		map->key.w = 1;
	if (keycode == LEFT_KEY)
		map->key.l = 1;
	if (keycode == RIGHT_KEY)
		map->key.r = 1;
	else if (keycode == ESC_KEY || keycode == Q_KEY)
		close_game(map);
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == A_KEY)
		map->key.a = 0;
	if (keycode == D_KEY)
		map->key.d = 0;
	if (keycode == S_KEY)
		map->key.s = 0;
	if (keycode == W_KEY)
		map->key.w = 0;
	if (keycode == LEFT_KEY)
		map->key.l = 0;
	if (keycode == RIGHT_KEY)
		map->key.r = 0;
	return (0);
}
