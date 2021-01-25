/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <alexandre.villar@hotmail.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:21 by avillar           #+#    #+#             */
/*   Updated: 2021/01/25 10:20:14 by avillar          ###   ########.fr       */
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
	static	int		i;
	int				d;

	str = ft_init(str);
	if (fd < 0 || (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	while ((d = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		ft_addtostr(str, buf);
		buf = ft_remalloc(buf);
		str = ft_remalloc(str);
		if (ft_strstr(buf, '\n') == 1)
			break ;
	}
	i++;
	fill_line(line, str);
	free(buf);
	if (d == 0)
		return (0);
	return (1);
}
