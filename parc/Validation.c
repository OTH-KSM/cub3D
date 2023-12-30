/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 21:04:31 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	validate_input_and_file(int argc, char *argv[])
{
	int	len;
	int	fd;

	if (argc != 2)
	{
		write(2, "Syntax : ./cub3D namefile.cub\n", 17);
		return (-1);
	}
	len = ft_strlen(argv[1]);
	if (len == 4 || ft_strncmp(argv[1] + len - 4, ".cub", 4))
	{
		print_error_and_exit("Wrong file extention\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error_and_exit("opening file\n");
		return (-1);
	}
	close(fd);
	return (0);
}

// counted -> [maxlen, lines, last]
t_final	*validate_file_content(char *argv)
{
	int		*counted;
	t_elist	*head;
	char	**map;
	t_final	*data;
	int		fd;

	fd = open(argv, O_RDONLY);
	counted = return_statistics(argv);
	if (counted[1] == 0)
		print_error_and_exit("File Empty\n");
	head = check_elements(fd, counted[2]);
	map = check_map(fd, counted[0], counted[1], counted[2]);
	itterate_the_map(map, counted[1] - counted[2]);
	data = passing_the_data(head, map, counted[1] - counted[2]);
	free(counted);
	close(fd);
	return (data);
}

void	bring_data(char *tmp, int *stats, int *jeton, int *token)
{
	char	*trimed;
	int		len;

	trimed = ft_strtrim(tmp, " ");
	if (!(*jeton) && ft_strchr("10", trimed[0]))
	{
		*jeton = 1;
		*token = 1;
		stats[2] = stats[1];
	}
	if (*token)
	{
		len = ft_strlen(tmp);
		if (stats[0] < len)
			stats[0] = len;
	}
	free(trimed);
	stats[1]++;
}

int	*return_statistics(char *argv)
{
	int		*stats;
	int		fd;
	int		jeton;
	int		token;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	stats = malloc(3 * sizeof(int));
	ft_bzero(stats, 12);
	jeton = 0;
	token = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp)
			bring_data(tmp, stats, &jeton, &token);
		else
		{
			if (jeton == 0)
				stats[2] = stats[1];
			break ;
		}
		free(tmp);
	}
	return (stats);
}

t_elist	*inialize_linked_list(void)
{
	int		i;
	t_elist	*elem;
	t_elist	*head;

	elem = malloc(sizeof(t_elist));
	head = elem;
	i = 0;
	while (i < 6)
	{
		elem->found = 0;
		elem->key = NULL;
		elem->value1 = NULL;
		elem->value2 = NULL;
		elem->value3 = NULL;
		elem->next_elem = malloc(sizeof(t_elist));
		if (i == 5)
		{
			free(elem->next_elem);
			elem->next_elem = NULL;
		}
		elem = elem->next_elem;
		i++;
	}
	return (head);
}
