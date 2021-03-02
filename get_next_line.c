/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:21 by avillar           #+#    #+#             */
/*   Updated: 2021/01/26 15:29:22 by marvin           ###   ########.fr       */
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

int		end(char **line, char *str, char *buf, int x)
{
	int		i;

	i = 0;
	if (buf)
		free(buf);
	if ((i = fill_line(line, str)) == -1)
		return (-1);
	/* c'est ce if la avec son leak qu'il faut tester car en fait avant dans le main de faisait un free en sortant du while qui appelait gnl et du coup bah mes test marchait mais
	 en fait c'était pas bon du coup j'ai mis un free ici et ça  a l'air de marcher par contre sur mes testeur ça mettais double free donc bon jte laisse tester merci.*/
	if (i == x)
	{
		if (*line)
			free(*line);
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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
	static	int		x;

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
	//ft_putstr(&str);
	printf("adresse de str = %p\n", str);
	printf("adresse de buf = %p\n", buf);
	printf("adresse de line = %p\n", *line);
	i = end(line, str, buf, x);
	if (d == -1 || i == -1)
		return (-1);
	if ((d == 0 && x == i))
		return (0);
	return (1);
}
