/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:17:05 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/20 16:18:31 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    _ItterateTheMap(char **map, int mapL) {
	int i = 0;
	int j;
	int count = 0;
	while (map[i])  {
		j = 0;
		if (ft_strchr(map[i], '+'))	{
			write(2, "Error\nma map ma walo\n", 21);
			exit (1);
		}
		while (map[i][j])   {
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1) {
		write(2, "Error\nMultiplayers in the map\n", 30);
		exit (1);
	}
	if(_ParsFirstLine(map, mapL)|| _ParsLastLine(map, mapL)|| _ParsMiddle(map, mapL)) {
		write(2, "Error\nMap validation failed\n", 28);
		exit (1);
	}
}

int    _ParsFirstLine(char **map, int mapL)  {
	int i = 0;
	// printf("First\n");
	while (map[0][i] && map[0][i] != '*')   {
		if (map[0][i] != '1' && map[0][i] != ' ') {
			return (-1);
		}
		else if (map[0][i] == ' ')
		{
			if (mapL > 1 && map[1][i] != ' ' && map[1][i] != '1')   {
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int    _ParsLastLine(char **map,int mapL)  {
	int i = 0;
	mapL -= 1;
	// printf("Last\n");
	while (map[mapL][i] && map[mapL][i] != '*')   {
		if (map[mapL][i] != '1' && map[mapL][i] != ' ') {
			return (-1);
		}
		else if (map[mapL][i] == ' ')
		{
			if (map[mapL - 1][i] != ' ' && map[mapL - 1][i] != '1')   {
				return (-1);
			}
		}
		i++;
	}
	return (0);
	// Note that this logic accept an emty last line means that the last line can be all just '*'
}

int		_ParsMiddle(char **map, int mapL) {
	int i = 0;
	int j = 0;
	// printf("Middle\n");
	if (mapL <= 2)
		return (-1);
	while (i < mapL - 1)	{
		j = 0;
		while (map[i][j] && map[i][j] != '*')	{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')	{
				if (j == 0)
					return (-1);
				if (j > 0 && map[i][j - 1] == ' ')
					return (-1);
				if (map[i][j + 1] && (map[i][j + 1] == ' ' || map[i][j + 1] == '*'))
					return (-1);
				if (map[i - 1][j] == ' ')
					return (-1);
				if (map[i + 1][j] == ' ')
					return (-1);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

