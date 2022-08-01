/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:07:11 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 08:54:58 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->element.ea)
		free_str(map->element.ea);
	if (map->element.we)
		free_str(map->element.we);
	if (map->element.so)
		free_str(map->element.so);
	if (map->element.no)
		free_str(map->element.no);
	if (map->element.f)
		free_str(map->element.f);
	if (map->element.c)
		free_str(map->element.c);
	while (map->buf && map->buf[++i])
		free(map->buf[i]);
	if (map->buf)
		free(map->buf);
	free (map);
}

void	free_window(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_destroy_image(map->mlx, map->tex[i++].img);
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	map->win = 0;
}

void	handle_err(int keyCode, t_map *map)
{
	if (keyCode == 0)
	{
		printf("fd eror\n");
		free_map(map);
		exit(1);
	}
	else if (keyCode == 1)
	{
		printf("ARG FORMAT ERROR/n");
		free_map(map);
		exit(1);
	}
	else if (keyCode == 2)
	{
		printf("Error arg Elements\n");
		free_map(map);
		exit(1);
	}
}

int	check_fc(char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
		return (1);
	else
		return (0);
}
