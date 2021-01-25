/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <alexandre.villar@hotmail.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:21 by avillar           #+#    #+#             */
/*   Updated: 2021/01/25 14:05:18 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strstr(char *haystack, char c)
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

int	get_next_line(int fd, char **line)
{
	static	char	*str;
	char			*buf;
	int				i;
	int				d;
	int				x;

	str = ft_init(str);
	if (fd < 0 || (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	while ((d = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[d] = '\0';
		ft_addtostr(str, buf);
		buf = ft_remalloc(buf);
		str = ft_remalloc(str);
		x = d;
		if (ft_strstr(buf, '\n') == 1)
			break ;
	}
	if ((i = fill_line(line, str)) == -1)
		return (-1);
	free(buf);
	if (d == 0 && x == i)
		return (0);
	return (1);
}