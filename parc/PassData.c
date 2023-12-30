/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:24:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 19:18:13 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	rgb_to_int(int R, int G, int B)
{
	return ((R << 16) | (G << 8) | B);
}

void	free_elem(t_elist *head)
{
	t_elist	*tmp;

	while (head)
	{
		if (head->key)
			free(head->key);
		if (head->value1)
			free(head->value1);
		if (head->value2)
			free(head->value2);
		if (head->value3)
			free(head->value3);
		tmp = head;
		head = head->next_elem;
		free(tmp);
	}
}

void	pass_elem(t_elist *met, t_final *data)
{
	while (met)
	{
		if (!ft_strncmp(met->key, "NO", 2))
			data->no = ft_strdup(met->value1);
		else if (!ft_strncmp(met->key, "SO", 2))
			data->so = ft_strdup(met->value1);
		else if (!ft_strncmp(met->key, "EA", 2))
			data->ea = ft_strdup(met->value1);
		else if (!ft_strncmp(met->key, "WE", 2))
			data->we = ft_strdup(met->value1);
		else if (!ft_strncmp(met->key, "F", 1))
			data->f = rgb_to_int(ft_atoi(met->value1),
					ft_atoi(met->value2), ft_atoi(met->value3));
		else if (!ft_strncmp(met->key, "C", 1))
			data->c = rgb_to_int(ft_atoi(met->value1),
					ft_atoi(met->value2), ft_atoi(met->value3));
		met = met->next_elem;
	}
}

void	pass_map(char **map, t_final *data, int lines)
{
	int		i;
	char	*tmp;

	i = 0;
	data->map = ft_calloc(lines + 1, sizeof(char *));
	if (data->map == NULL)
		print_error_and_exit("Allocation Failed\n");
	while (map[i])
	{
		tmp = ft_strtrim(map[i], "*");
		if (i == 0)
			data->width = ft_strlen(tmp);
		data->map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}

t_final	*passing_the_data(t_elist *met, char **map, int lines)
{
	t_final	*data;
	t_elist	*head;
	int		i;

	head = met;
	i = 0;
	data = ft_calloc(1, sizeof(t_final));
	data->height = lines;
	pass_elem(met, data);
	pass_map(map, data, lines);
	free_elem(head);
	free_2d_array(map);
	return (data);
}
