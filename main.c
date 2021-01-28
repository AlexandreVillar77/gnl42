/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:26:51 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 14:16:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	/*if (argc != 2) {
		return (0);
	}*/
	(void) argc;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0) {
		printf("%s\n", line);
		free(line);
	}
	//free(line);
	close(fd);
	return (0);
}
/*
int     main(void) {
        int             fd = -1;
        char    *line = NULL;
        int             ret;

        open file - if an error occurs here, the test will be ignored, that's not your fault !
        if ((fd = open("text.txt", O_RDONLY)) == -1 || read(fd, NULL, 0) == -1) {
                return (-1);
        }

        while ((ret = get_next_line(fd, &line)) > 0) {
                printf("%s\n", line);
                free(line);
                line = NULL;
        }
        printf("return value: %d\n", ret);
        free(line);

        cleaning up 
        close(fd);
		printf("%s\n", "success");
        return (0);
}

int	main()
{
	int		fd;
	char	*line;
	int		rtnvalue;

	fd = 1;
	fd = open("text.txt", O_RDONLY);
	rtnvalue = get_next_line(fd, &line);
	printf("result 1 : %d \n", rtnvalue);
	printf("result 1 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 2 : %d \n", rtnvalue);
	printf("result 2 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 3 : %d \n", rtnvalue);
	printf("result 3 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 4 : %d \n", rtnvalue);
	printf("result 4 : %s \n", line);
	free(line);
	rtnvalue = get_next_line(fd, &line);
	printf("result 5 : %d \n", rtnvalue);
	printf("result 5 : %s \n", line);
	free(line);
    rtnvalue = get_next_line(fd, &line);
	printf("result 6 : %d \n", rtnvalue);
	printf("result 6 : %s \n", line);
	free(line);
	close(fd);
	return (0);
}*/