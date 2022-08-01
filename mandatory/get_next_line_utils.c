/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:15:57 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/09 17:18:48 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int	str_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	if (s1 == NULL)
		return (s2);
	if (s1 && s2)
	{	
		i = 0;
		new = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2)) + 1);
		if (new == 0)
			return (0);
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		k = 0;
		while (s2[k])
			new[i++] = s2[k++];
		new[i] = '\0';
		return (new);
	}
	return (0);
}

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = str_len(s);
	if (!s)
		return (-2);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (j);
	return (-1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	j = 0;
	i = -1;
	if (!s)
		return (0);
	str = NULL;
	if (len > str_len(s) - start)
		str = (char *)malloc(sizeof(char) * (str_len(s) - start) + 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		while (s[++i])
			if (i >= start && j < len)
				str [j++] = s[i];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(str_len(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
