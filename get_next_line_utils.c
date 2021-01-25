/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:21 by avillar           #+#    #+#             */
/*   Updated: 2021/01/25 17:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen_gnl(char *str, int mod)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	if (mod == 1)
	{
		while (str[i] != '\n' && str[i])
			i++;
	}
	else if (mod == 2)
	{
		while (str[i])
			i++;
	}
	else if (mod == 3)
	{
		while (str[i++])
			if (str[i] == '\n')
				l++;
		return (l);
	}
	return (i);
}

void	ft_addtostr(char *str, char *buf)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		i++;
	}
	while (buf[x])
	{
		str[i] = buf[x];
		x++;
		i++;
	}
	str[i] = '\0';
}

char	*ft_remalloc(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = malloc(sizeof(char) * ft_strlen_gnl(str, 2) + 1)))
		return (0);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	if (!(str = malloc(sizeof(char) * i + BUFFER_SIZE + 1)))
		return (0);
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	free(tmp);
	return (str);
}

char	*ft_init(char *str)
{
	if (!str)
	{
		if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (0);
		str[0] = '\0';
	}
	return (str);
}

int		fill_line(char **line, char *str)
{
	int			x;
	static	int	i;

	x = 0;
	if (x == 0 && str[i] == '\n' && i != 0 && str[i])
		i++;
	if (!(*line = malloc(sizeof(char) * ft_strlen_gnl(str + i, 1) + 1)))
		return (-1);
	while (str[i] && str[i] != '\n')
	{
		(*line)[x] = str[i];
		x++;
		i++;
	}
	if (i == 0)
		i++;
	(*line)[x] = '\0';
	return (i);
}
