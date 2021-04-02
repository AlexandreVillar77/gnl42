/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:53:27 by marvin            #+#    #+#             */
/*   Updated: 2021/04/02 12:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_linelen(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *src);
char	*ft_strcat(char *src, char *tmp);
char	*checkbuf(char *buf, char *keep);
char	*putline(char *keep);
int		get_next_line(int fd, char **line);

#endif
