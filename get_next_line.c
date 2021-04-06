/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:53:04 by marvin            #+#    #+#             */
/*   Updated: 2021/04/02 13:54:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleankeep(char *keep, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strlen(keep) == len)
	{
		free(keep);
		return (NULL);
	}
	if (keep[len] == '\n')
		len++;
	if (!(tmp = malloc(sizeof(char) * ((ft_strlen(keep) - len) + 1))))
		return (0);
	while (keep[i + len])
	{
		tmp[i] = keep[i + len];
		i++;
	}
	tmp[i] = '\0';
	free(keep);
	return (tmp);
}

int		ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		is_line(char *keep)
{
	int		i;

	i = 0;
	if (keep)
	{
		while (keep[i] != '\n' && keep[i] != '\0')
			i++;
		if (keep[i] == '\n')
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			x;
	static char	*keep;

	x = 1;
	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
		(!(buf = malloc(BUFFER_SIZE + 1))))
		return (-1);
	while (is_line(keep) == 0 && x != 0)
	{
		if ((x = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[x] = '\0';
		keep = checkbuf(buf, keep);
	}
	free(buf);
	*line = putline(keep);
	keep = cleankeep(keep, ft_strlen(*line));
	if (x == 0)
		return (0);
	return (1);
}
