/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:22 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 13:32:54 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_error_and_exit(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit (1);
}

int	print_error_and_return(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (-1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*removespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C' || str[i] == 'F')
			return (str + i);
		i++;
	}
	return (NULL);
}

void	verify_filling(t_elist *elem)
{
	while (elem)
	{
		if (elem->found != 1)
			print_error_and_exit("Missing Elements or Elements Repetition\n");
		if (elem->Genre == 0)
		{
			if (check_dir_values(elem) == -1)
				exit (1);
		}
		else if (elem->Genre == 1)
		{
			if (check_col_values(elem) == -1)
				exit (1);
		}
		elem = elem->next_elem;
	}
}

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

// count -> [NO, SO, WE, EA]
t_elist	*check_elements(int fd, int last)
{
	int		i;
	t_elist	*head;
	t_elist	*elem;
	char	*line;
	char	*tmp;
	int		len;

	i = 0;
	elem = _InializeLinkedList();
	head = elem;
	while (i < last)
	{
		line = get_next_line(fd);
		if (line && line[0] != '\n')
		{
			len = ft_strlen(line);
			if (line[len - 1] == '\n')
			{
				tmp = line;
				line = ft_substr(line, 0, len - 1);
				free(tmp);
			}
			if (elem)
			{
				if (it_match_dir(elem, line, ft_split("NO -SO -WE -EA ", '-'), 1))
					fill_dir(elem, line);
				else if (it_match_col(elem, line, ft_split("C -F ", '-'), 1))
					fill_col(elem, line);
				else
					print_error_and_exit("Wrong Type of Element\n");
				elem = elem->next_elem;
			}
			else
				print_error_and_exit("Too Many Map Type of Elements\n");
		}
		free(line);
		i++;
	}
	elem = head;
	verify_filling(elem);
	return (head);
}

bool	it_match_dir(t_elist *elem, char *sample, char **solutions, int token)
{
	char		*tmp;
	static int	count[4];

	tmp = ft_strtrim(sample, " ");
	if (!ft_strncmp(tmp, solutions[0], 3) || !ft_strncmp(tmp, solutions[1], 3)
		|| !ft_strncmp(tmp, solutions[2], 3)
		|| !ft_strncmp(tmp, solutions[3], 3))
	{
		if (token == 1)
		{
			if (!ft_strncmp(tmp, solutions[0], 3))
				elem->found = ++(count[0]);
			else if (!ft_strncmp(tmp, solutions[1], 3))
				elem->found = ++(count[1]);
			else if (!ft_strncmp(tmp, solutions[2], 3))
				elem->found = ++(count[2]);
			else if (!ft_strncmp(tmp, solutions[3], 3))
				elem->found = ++(count[3]);
		}
		free(tmp);
		free_2d_array(solutions);
		return (true);
	}
	else
	{
		free(tmp);
		free_2d_array(solutions);
		return (false);
	}
}

//count -> [F, C]
bool	it_match_col(t_elist *elem, char *sample, char **solutions, int token)
{
	static int	count[2];
	char		*tmp;

	tmp = ft_strtrim(sample, " ");
	if (!ft_strncmp(tmp, solutions[0], 2) || !ft_strncmp(tmp, solutions[1], 2))
	{
		if (token == 1)
		{
			if (!ft_strncmp(tmp, solutions[0], 2))
				elem->found = ++(count[0]);
			else if (!ft_strncmp(tmp, solutions[1], 2))
				elem->found = ++(count[1]);
		}
		free(tmp);
		free_2d_array(solutions);
		return (true);
	}
	else
	{
		free(tmp);
		free_2d_array(solutions);
		return (false);
	}
}

int	check_dir_values(t_elist *elem)
{
	int	len;

	if (elem->Value1)
	{
		len = ft_strlen(elem->Value1);
		if (len <= 4 || (len > 4 && strncmp(elem->Value1 + len - 4, ".xpm", 4)))
			return(print_error_and_return("Direction Elements's Path Are not Valid\n"));
		else if ((open(elem->Value1, O_RDONLY)) == -1)
			return(print_error_and_return("Direction Elements's Path Can't Open\n"));
	}
	else
	{
		write(2, "Error\nMissing Directions's elements Path\n", 41);
		return (-1);
	}
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
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
			return (print_error_and_return("Colors elements's Values are not digits\n"));
		a1 = ft_atoi(elem->Value1);
		a2 = ft_atoi(elem->Value2);
		a3 = ft_atoi(elem->Value3);
		if (!(a1 >= 0 && a1 <= 255) || !(a2 >= 0 && a2 <= 255)
			|| !(a3 >= 0 && a3 <= 255))
			return (print_error_and_return("Colors elements's Values are out of range\n"));
	}
	return (0);
}
