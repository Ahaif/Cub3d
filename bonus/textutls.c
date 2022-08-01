/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textutls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:55:30 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/04 15:56:07 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_tex(t_map *map)
{
	map->texinfo.p[0] = rem_bs(map->element.no[1]);
	map->texinfo.p[1] = rem_bs(map->element.so[1]);
	map->texinfo.p[2] = rem_bs(map->element.we[1]);
	map->texinfo.p[3] = rem_bs(map->element.ea[1]);
	map->texinfo.p[4] = "./textures/door2.xpm";
	map->texinfo.p[5] = "./textures/1.xpm";
	map->texinfo.p[6] = "./textures/2.xpm";
	map->texinfo.p[7] = "./textures/3.xpm";
	map->texinfo.p[8] = "./textures/4.xpm";
	map->texinfo.p[9] = "./textures/5.xpm";
	map->texinfo.p[10] = NULL;
}

int	draw_tex(t_map *map)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		map->tex[i].img = mlx_xpm_file_to_image
			(map->mlx, map->texinfo.p[i],
				&map->tex[i].width, &map->tex[i].height);
		if (i != 4)
			free(map->texinfo.p[i]);
		if (!map->tex[i].img)
			return (free_window_tex(map));
		map->tex[i].addr = (int *)mlx_get_data_addr
			(map->tex[i].img, &map->tex[i].bits_per_pixel,
				&map->tex[i].line_length, &map->tex[i].endian);
		if (!map->tex[i].addr)
			return (free_window_tex(map));
		i++;
	}
	return (i);
}

int	add_text_img(t_map *map)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	assign_tex(map);
	i = draw_tex(map);
	while (i < 10)
	{
		map->texp[y].img = mlx_xpm_file_to_image
			(map->mlx, map->texinfo.p[i],
				&map->texp[y].width, &map->texp[y].height);
		if (!map->texp[y].img)
			return (free_window_tex(map));
		map->texp[y].addr = (int *)mlx_get_data_addr
			(map->texp[y].img, &map->texp[y].bits_per_pixel,
				&map->texp[y].line_length, &map->texp[y].endian);
		if (!map->texp[y].addr)
			return (free_window_tex(map));
		i++;
		y++;
	}
	return (1);
}
