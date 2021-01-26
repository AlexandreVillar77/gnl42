/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:21 by avillar           #+#    #+#             */
/*   Updated: 2021/01/26 15:14:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strstr(char *haystack, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (haystack[i])
	{
		if (haystack[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buf)
{
	ft_addtostr(str, buf);
	str = ft_remalloc(str);
	return (str);
}

int		end(char **line, char *str, char *buf, int d)
{
	int		i;

	i = 0;
	if (buf)
		free(buf);
	if (d == -1)
		return (-1);
	if ((i = fill_line(line, str)) == -1)
		return (-1);
	return (i);
}

char	*malbuf(int fd, char **line)
{
	char	*buf;

	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str;
	char			*buf;
	int				i;
	int				d;
	static int		x;

	if (!(buf = malbuf(fd, line)))
		return (-1);
	str = ft_init(str);
	while ((d = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[d] = '\0';
		str = ft_strjoin(str, buf);
		buf = ft_remalloc(buf);
		if (d != 0 || x == x + d)
			x += d;
		if (ft_strstr(buf, '\n') == 1)
			break ;
	}
	i = end(line, str, buf, d);
	if (d == -1 || i == -1)
		return (-1);
	if ((d == 0 && x == i && str[i + 1] != '\n') || (x == i - 1))
		return (0);
	return (1);
}
