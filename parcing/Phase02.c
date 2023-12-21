/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:54 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/21 12:00:00 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char    **_CheckMap(int fd, int maxlen, int lines, int last)  {
	int i = 0;
	char *str;
	char **map;
	// if no line in the part of the map so print an error
	if (!maxlen)    {
		write(2, "Error\nEmty map\n", 15);
		exit (1);
	}
	map = ft_calloc(lines - last + 1, sizeof(char *));
	while ((str = get_next_line(fd)))    {
		map[i] = _Fill(str, maxlen);
		free(str);
		i++;
	}
	close(fd);
	return (map);
}

char    *_Fill(char *str, int maxlen)   {
	char *new;
	int i = 0;
	int j;

	new = ft_calloc(maxlen + 1, sizeof(char));
	while (str[i] && str[i] != '\n')  {
		if (!ft_strchr("NSWE10 ", str[i]))   {
			write(2, "Error\nWrong Character in the Map\n", 33);
			exit (1);
		}
		new[i] = str[i];
		i++;
	}
	j = i;
	while (i < maxlen - 1) {
		new[i] = ' ';
		i++;
	}
	// ISSUE #9
	if (str[j] == '\n')	{
		if (j == 0)
			new[i] = '+';
		else
			new[i] = '*';	
	}
	return (new);
}