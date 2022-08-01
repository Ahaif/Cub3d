/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <foulare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/11 15:11:00 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init(t_map *map)
{
	map->color_f = convert_rgb(map->element.f[1]);
	map->color_c = convert_rgb(map->element.c[1]);
	map->img = NULL;
	map->key.a = 0;
	map->key.w = 0;
	map->key.s = 0;
	map->key.d = 0;
	map->key.l = 0;
	map->key.r = 0;
	map->fov = 60;
	init_tex(map);
	return (1);
}

int	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if (strcmp(&av[i], ".cub") == 0)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

void	boot_cub3d(char **av, t_map *map)
{
	if (!check_extension(av[1]))
	{
		perror ("extension file is not compatible");
		free_map(map);
		exit (1);
	}
	if (!read_map(av[1], map))
	{
		free_map(map);
		exit(1);
	}
}

void	start_game(t_map *map)
{
	if (!ft_init(map))
	{
		perror("initialization erro ");
		free_window(map);
		exit (1);
	}
	if (!add_text_img(map))
	{	
		perror("texture_error");
		free_window(map);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		printf("Error arguments/n");
		return (1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	boot_cub3d(av, map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width, map->heigth, "CUB-3D");
	start_game(map);
	mlx_loop_hook(map->mlx, raycaster, (void *)map);
	mlx_hook(map->win, 2, 0, key_press, map);
	mlx_hook(map->win, 3, 0, key_release, map);
	mlx_hook(map->win, 17, 0, ft_close, (void *)map);
	mlx_loop (map->mlx);
	return (0);
}
