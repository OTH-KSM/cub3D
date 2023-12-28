/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:22 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 16:17:37 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool return_bool(char *tmp, char **solutions, bool value)
{
	free(tmp);
	free_2d_array(solutions);
	return (value);
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
		|| !ft_strncmp(tmp, solutions[2], 3) || !ft_strncmp(tmp, solutions[3], 3))
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
		return (return_bool(tmp, solutions, 1));
	}
	return (return_bool(tmp, solutions, 0));
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
		return (return_bool(tmp, solutions, 1));
	}
	return (return_bool(tmp, solutions, 0));
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
