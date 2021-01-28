/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:49:53 by avillar           #+#    #+#             */
/*   Updated: 2021/01/28 14:26:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_gnl(char *str, int mod);
void	ft_addtostr(char *str, char *buf);
int		ft_strstr(char *haystack, char c);
char	*ft_init(char *str);
char	*ft_remalloc(char *str);
int		end(char **line, char *str, char *buf, int d);
char	*malbuf(int fd, char **line);
char	*ft_strjoin(char *str, char *buf);
int		fill_line(char **line, char *str);
int		get_next_line(int fd, char **line);

#endif
