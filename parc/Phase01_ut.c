/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase01_ut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:45:13 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 15:28:54 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	fill_dir(t_elist *elem, char *line)
{
	char	**splited;

	splited = ft_split(line, ' ');
	elem->Key = ft_strdup(splited[0]);
	if (splited[1])
	{
		elem->Value1 = ft_strdup(splited[1]);
		if (splited[2])
			print_error_and_exit("Too many Directions Arguments\n");
	}
	free_2d_array(splited);
	elem->Genre = 0;
}

void	fill_col(t_elist *elem, char *line)
{
	char	**splited;

	if (line[ft_strlen(line) - 1] == ',')
		print_error_and_exit("Missing Colors Arguments\n");
	splited = ft_split((removespaces(line) + 1), ',');
	elem->Key = ft_substr(line, 0, 1);
	if (splited[0])
	{
		elem->Value1 = ft_strtrim(splited[0], " ");
		if (splited[1])
		{
			elem->Value2 = ft_strtrim(splited[1], " ");
			if (splited[2])
			{
				elem->Value3 = ft_strtrim(splited[2], " ");
				if (splited[3])
					print_error_and_exit("Too Many Colors Arguments\n");
			}
		}
	}
	free_2d_array(splited);
	elem->Genre = 1;
}

int	check_dir_values(t_elist *elem)
{
	int	len;

	if (elem->Value1)
	{
		len = ft_strlen(elem->Value1);
		if (len <= 4 || (len > 4 && strncmp(elem->Value1 + len - 4, ".xpm", 4)))
			return (print_error_and_return("Direction Path Are not Valid\n"));
		else if ((open(elem->Value1, O_RDONLY)) == -1)
			return (print_error_and_return("Direction Path Can't Open\n"));
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

	if (!elem->Value1 || !elem->Value2 || !elem->Value3)
	{
		write(2, "Error\nMissing Colors's elements Values\n", 39);
		return (-1);
	}
	else
	{
		if (is_digit(elem->Value1) || is_digit(elem->Value2)
			|| is_digit(elem->Value3))
			return (print_error_and_return("Colors Values Are Not Digits\n"));
		a1 = ft_atoi(elem->Value1);
		a2 = ft_atoi(elem->Value2);
		a3 = ft_atoi(elem->Value3);
		if (!(a1 >= 0 && a1 <= 255) || !(a2 >= 0 && a2 <= 255)
			|| !(a3 >= 0 && a3 <= 255))
			return (print_error_and_return("Colors Values are out of range\n"));
	}
	return (0);
}