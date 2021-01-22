/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <alexandre.villar@hotmail.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:49:53 by avillar           #+#    #+#             */
/*   Updated: 2021/01/21 16:45:22 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen_gnl(char *str, int mod);
void	ft_addtostr(char *str, char *buf);
int		ft_strstr(char *haystack, char c);
char	*ft_init(char *str);
char	*ft_remalloc(char *str);
char	**ft_read(int fd);
int		get_next_line(int fd, char **line);
void	fill_line(char **line, char *str);

#endif
