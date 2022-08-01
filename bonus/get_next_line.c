/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:41:25 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 20:10:32 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_newline(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	return (i);
}

int	check_error(ssize_t out, char *buffer, char *rest)
{
	if (out < 0)
	{
		free (buffer);
		if (rest != NULL)
			free (rest);
		return (1);
	}
	else if (out == 0 && rest == NULL)
	{
		free (buffer);
		return (1);
	}
	else if (rest[0] == '\0')
	{
		free(rest);
		free(buffer);
		return (1);
	}
	free(buffer);
	return (0);
}

static char	*fill_rest(char *rest, char *buffer, int fd)
{
	char	*temp;
	ssize_t	out;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	out = read(fd, buffer, BUFFER_SIZE);
	while (out > 0)
	{
		buffer[out] = 0;
		if (rest == 0)
			rest = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(rest, buffer);
			free (rest);
			rest = temp;
		}
		if (ft_strchr(rest, '\n') >= 0)
			break ;
		out = read(fd, buffer, BUFFER_SIZE);
	}
	if (check_error(out, buffer, rest))
		return (0);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest;
	char		*temp;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = NULL;
	rest = fill_rest(rest, buffer, fd);
	if (!rest)
		return (NULL);
	if (rest[ft_newline(rest)] == '\n')
	{
		line = ft_substr(rest, 0, ft_newline(rest) + 1);
		temp = ft_strdup(&rest[ft_newline(rest) + 1]);
		free(rest);
		rest = temp;
	}
	else
	{
		line = ft_strdup(rest);
		free(rest);
		rest = NULL;
	}
	return (line);
}
