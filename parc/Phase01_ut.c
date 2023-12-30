/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase01_ut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:45:13 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 19:12:24 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	fill_dir(t_elist *elem, char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	elem->key = ft_strdup(splited[0]);
	if (splited[1])
	{
		elem->value1 = ft_strdup(splited[1]);
		if (splited[2])
			print_error_and_exit("Too many Directions Arguments\n");
	}
	free_2d_array(splited);
	elem->genre = 0;
}

void	fill_col(t_elist *elem, char *line)
{
	char	**splited;

	if (line[ft_strlen(line) - 1] == ',')
		print_error_and_exit("Missing Colors Arguments\n");
	splited = ft_split((removespaces(line) + 1), ',');
	elem->key = ft_substr(line, 0, 1);
	if (splited[0])
	{
		elem->value1 = ft_strtrim(splited[0], " ");
		if (splited[1])
		{
			elem->value2 = ft_strtrim(splited[1], " ");
			if (splited[2])
			{
				elem->value3 = ft_strtrim(splited[2], " ");
				if (splited[3])
					print_error_and_exit("Too Many Colors Arguments\n");
			}
		}
	}
	free_2d_array(splited);
	elem->genre = 1;
}

int	check_dir_values(t_elist *elem)
{
	int	len;

	if (elem->value1)
	{
		len = ft_strlen(elem->value1);
		if (len <= 4 || (len > 4 && strncmp(elem->value1 + len - 4, ".xpm", 4)))
			return (print_error_and_return("Invalid Direciton Path\n"));
		else if ((open(elem->value1, O_RDONLY)) == -1)
			return (print_error_and_return("Failled opennig Direction file\n"));
	}
	else
	{
		write(2, "Error\nMissing Directions's elements Path\n", 41);
		return (-1);
	}
	return (0);
}

int	check_col_values(t_elist *elem)
{
	int	a1;
	int	a2;
	int	a3;

	if (!elem->value1 || !elem->value2 || !elem->value3)
	{
		write(2, "Error\nMissing Colors's elements Values\n", 39);
		return (-1);
	}
	else
	{
		if (is_digit(elem->value1) || is_digit(elem->value2)
			|| is_digit(elem->value3))
			return (print_error_and_return("Colors Values Are Not Digits\n"));
		a1 = ft_atoi(elem->value1);
		a2 = ft_atoi(elem->value2);
		a3 = ft_atoi(elem->value3);
		if (!(a1 >= 0 && a1 <= 255) || !(a2 >= 0 && a2 <= 255)
			|| !(a3 >= 0 && a3 <= 255))
			return (print_error_and_return("Colors Values are out of range\n"));
	}
	return (0);
}
