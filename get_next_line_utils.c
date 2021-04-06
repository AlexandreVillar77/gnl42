/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:55:36 by marvin            #+#    #+#             */
/*   Updated: 2021/04/02 13:00:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *src, char *tmp)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(src) + 1))))
		return (0);
	while (tmp[i])
	{
		dst[i] = tmp[i];
		i++;
	}
	while (src[x])
	{
		dst[i] = src[x];
		x++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*checkbuf(char *buf, char *keep)
{
	int		i;
	char	*tmp;

	i = 0;

	if (!keep)
	{
		if (!(keep = malloc(sizeof(char) * 1)))
			return (0);
		keep[0] = '\0';
	}
	tmp = ft_strcpy(keep);
	free(keep);
	keep = ft_strcat(buf, tmp);
	free(tmp);
	return (keep);
}

char	*putline(char *keep)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * ft_linelen(keep) + 1)))
		return (0);
	while (keep[i] != '\n' && keep[i] != '\0')
	{
		dst[i] = keep[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
