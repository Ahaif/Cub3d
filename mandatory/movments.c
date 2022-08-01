/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:54:16 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 11:34:36 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_map *map)
{
	map->player_angle -= 10;
	map->player_angle %= 360;
}

void	move_right(t_map *map)
{
	map->player_angle += 10;
	map->player_angle %= 360;
}

void	move_backforth(t_map *map, double x, double y)
{
	map->player_x += x;
	map->player_y += y;
}

void	rotateangle(t_map *map, double x, double y)
{
	map->player_x -= x;
	map->player_y -= y;
}

void	close_game(t_map *map)
{
	free_window(map);
	free_map(map);
	exit(0);
}
