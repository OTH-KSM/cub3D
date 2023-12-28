/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:24:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 20:40:48 by okassimi         ###   ########.fr       */
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
		if (head->Key)
			free(head->Key);
		if (head->Value1)
			free(head->Value1);
		if (head->Value2)
			free(head->Value2);
		if (head->Value3)
			free(head->Value3);
		tmp = head;
		head = head->next_elem;
		free(tmp);
	}
}

void	pass_elem(t_elist *met, t_final *data)
{
	while (met)
	{
		if (!ft_strncmp(met->Key, "NO", 2))
			data->no = ft_strdup(met->Value1);
		else if (!ft_strncmp(met->Key, "SO", 2))
			data->so = ft_strdup(met->Value1);
		else if (!ft_strncmp(met->Key, "EA", 2))
			data->ea = ft_strdup(met->Value1);
		else if (!ft_strncmp(met->Key, "WE", 2))
			data->we = ft_strdup(met->Value1);
		else if (!ft_strncmp(met->Key, "F", 1))
			data->F = rgb_to_int(ft_atoi(met->Value1),
					ft_atoi(met->Value2), ft_atoi(met->Value3));
		else if (!ft_strncmp(met->Key, "C", 1))
			data->C = rgb_to_int(ft_atoi(met->Value1),
					ft_atoi(met->Value2), ft_atoi(met->Value3));
		met = met->next_elem;
	}
}

void	pass_map(char **map, t_final *data, int lines)
{
	int		i;
	char	*tmp;

	i = 0;
	data->map = ft_calloc(lines + 1, sizeof(char *));
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
	char	*tmp;
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
