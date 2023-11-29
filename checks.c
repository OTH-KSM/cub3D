/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 14:04:42 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	_ValidateInputAndFile(int argc, char *argv[])	{
	if (argc != 2) {
		write(2, "Error: argument\n", 16);
		return (-1);
	}
	int len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4))	{
		write(2, "Error: file extention\n", 22);
		return (-1);
	}
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == -1)	{
		write(2, "Error: file\n", 13);
		return (-1);
	}
	close(fd);
	return (0);
}

int*	_ReturnStatistics(char *argv)	{
	int *stats;
	int fd;
	int len;

	fd = open(argv, O_RDONLY);
	stats = malloc(2 * sizeof(int));
	ft_bzero(stats, 8);
	len = 1;
	while (1)	{
		if (stats[0] < (len = ft_strlen(get_next_line(fd))))
			stats[0] = len;
		stats[1]++;
		if (len == 0)
			break ;
	}
	close(fd);
	return (stats);
}


// int	_CheckEelements(char *argv)	{
// 	int fd = open(argv, O_RDONLY);
	
// }

int _ValidateFileContent(char *argv)	{
	// int fd = open(argv, O_RDONLY);
	int lines = _ReturnStatistics(argv)[1];
	int length = _ReturnStatistics(argv)[0];
	printf("%d\n%d\n", lines, length);
	// char **map = malloc(lines * sizeof(char *));
	// int i = 0;
	// while (lines)	{
	// 	map[i] = malloc(length * sizeof(char));
	// 	// I should copy the content
	// 	i++;
	// 	lines--;
	// }
	// close(fd);
	return (0);
}