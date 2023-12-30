/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:17:05 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 21:03:58 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	itterate_the_map(char **map, int mapL)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		if (ft_strchr(map[i], '+'))
			print_error_and_exit("Newline inside the Map\n");
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		print_error_and_exit("Missing or Multiplayers in the map\n");
	if (pars_first_line(map, mapL) || pars_last_line(map, mapL)
		|| pars_middle(map, mapL))
		print_error_and_exit("Map validation failed\n");
}

int	pars_first_line(char **map, int mapL)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '*')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (-1);
		else if (map[0][i] == ' ')
		{
			if (mapL > 1 && map[1][i] != ' ' && map[1][i] != '1')
				return (-1);
		}
		i++;
	}
	return (0);
}

/* line 81 : Note that this logic accept an emty last line means
	that the last line can be all just '*'*/
int	pars_last_line(char **map, int mapL)
{
	int	i;

	i = 0;
	mapL -= 1;
	while (map[mapL][i] && map[mapL][i] != '*')
	{
		if (map[mapL][i] != '1' && map[mapL][i] != ' ')
			return (-1);
		else if (map[mapL][i] == ' ')
		{
			if (map[mapL - 1][i] != ' ' && map[mapL - 1][i] != '1')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	pars_middle(char **map, int mapL)
{
	int	i;
	int	j;

	i = 0;
	if (mapL <= 2)
		return (-1);
	while (i < mapL - 1)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '*')
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (j == 0 || (j > 0 && map[i][j - 1] == ' ')
					|| (map[i][j + 1] && (map[i][j + 1] == ' '
					|| map[i][j + 1] == '*'))
				|| (map[i - 1][j] == ' ') || (map[i + 1][j] == ' '))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
