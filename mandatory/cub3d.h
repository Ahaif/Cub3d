/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:09:56 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/06/05 12:38:45 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include <math.h>
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define ESC_KEY 53

# define PI 3.14159265359

# include "mlx.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct info
{
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
	char	**f;
	char	**c;
}			t_info;

typedef struct key
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	l;
	int	r;
}		t_key;

typedef struct s_tex
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_tex;

typedef struct s_treed
{
	double	wall_h;
	int		start;
	int		texy;
	double	dis;
	double	step;
	double	texpos;
	double	xtex;
}			t_treed;

typedef struct data
{
	t_info			element;
	t_info			texinfo;
	t_tex			tex[5];
	t_treed			treed;
	double			ray_x;
	double			ray_y;
	t_key			key;
	int				fov;
	int				player_angle;
	int				i;
	double			player_x;
	double			player_y;
	int				width;
	int				heigth;
	char			**buf;
	void			*mlx;
	void			*win;
	int				color_f;
	int				color_c;
	void			*img;
	unsigned int	*img_buf;
	double			ray_angle;
	double			dist;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	int				lin;
	int				pix;
	int				d;
	double			incre;
}					t_map;
//parsing 
int		read_map(char *file, t_map *map);
void	initialize_map(t_map *map);
//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s1);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		str_len(const char *str);
# define BUFFER_SIZE 1000000
// utils
char	**ft_split(const char *s, char c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_concat(char *s1, char *s2);
int		check_map(t_map *map, char *str);
//hooks_keys
int		key_press(int keycode, t_map *map);
int		key_release(int keycode, t_map *map);
//texture
int		add_text_img(t_map *map);
char	*rm_bs(char *str);
void	ft_print(t_map *map);
int		raycaster(t_map *map);
double	to_radian(double angle);
void	move_backforwards(t_map *map);
char	*ft_itoa(int n);
int		ft_pos(char c); // check "0NWSN"
void	move_backforth(t_map *map, double x, double y);
void	rotateangle(t_map *map, double x, double y);
void	close_game(t_map *map);
void	free_map(t_map *map);
void	free_window(t_map *map);
void	init_tex(t_map *map);
void	initialize_map(t_map *map);
void	handle_err(int keyCode, t_map *map);
int		check_fc(char *line);
char	*free_previous_str(char *str, char *line);
int		fillmap(t_map *map);
int		ft_size(char **spltd);
void	draw_cel(t_map *map, int start, int x);
int		draw_walls(t_map *map, int start, double texpos, int x);
void	draw_floor(t_map *map, int i, int start, int x);
double	power(double x);
double	to_radian(double angle);
int		ft_pos(char c);
int		rem_map(t_map *map, int x, int y);
void	check_space(t_map *map, int x, int y);
int		check_rest(t_map *map, int x, int y);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	move(t_map *map);
int		key_release(int keycode, t_map *map);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *str, int c);
int		ft_close(t_map *map);
int		convert_rgb(char *str);
void	free_str(char **str);
int		ft_atoi(const char *str);
int		check_color(char **str);
#endif
