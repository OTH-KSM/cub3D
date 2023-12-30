/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:54 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 19:18:21 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//line 20 : if no line in the part of the map so print an error
char	**check_map(int fd, int maxlen, int lines, int last)
{
	int		i;
	char	*str;
	char	**map;

	i = 0;
	if (!maxlen)
		print_error_and_exit("Empty map\n");
	map = ft_calloc(lines - last + 1, sizeof(char *));
	if (!map)
		print_error_and_exit("Allocation Failled\n");
	str = get_next_line(fd);
	while (str)
	{
		map[i] = fill(str, maxlen);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	if (str)
		free(str);
	close(fd);
	return (map);
}

char	*fill(char *str, int maxlen)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc(maxlen + 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_strchr("NSwe10 ", str[i]))
			print_error_and_exit("Wrong Character in the Map\n");
		new[i] = str[i];
		i++;
	}
	j = i;
	while (i < maxlen - 1)
		new[i++] = ' ';
	if (str[j] == '\n')
	{
		if (j == 0)
			new[i] = '+';
		else
			new[i] = '*';
	}
	return (new);
}
