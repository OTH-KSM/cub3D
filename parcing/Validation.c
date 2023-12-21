/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/21 12:00:07 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	_ValidateInputAndFile(int argc, char *argv[])	{
	if (argc != 2) {
		write(2, "Error: Arguments\n", 17);
		return (-1);
	}
	int len = ft_strlen(argv[1]);
	if (len == 4 || ft_strncmp(argv[1] + len - 4, ".cub", 4))	{
		write(2, "Error: File extention\n", 22);
		return (-1);
	}
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == -1)	{
		write(2, "Error: opening file\n", 20);
		return (-1);
	}
	close(fd);
	return (0);
}

t_final	_ValidateFileContent(char *argv)	{
	// array instead of three variable when each one calls the _ReturnStatistics
	int *counted = _ReturnStatistics(argv); // [maxlen, lines, last]
	int fd = open(argv, O_RDONLY);
	// printf("maxlen: %d\nlines: %d\nlast: %d\n",counted[0], counted[1], counted[2]);
	// exit (0);
	if (counted[1] == 0)	{
		write(2, "Error: File Empty\n", 18);
		exit (1);
	}
	t_elist *head = _CheckEelements(fd, counted[2]);
	char **map = _CheckMap(fd, counted[0], counted[1], counted[2]);
	/*Printing the map*/
	// printf("printing map\n");
	// for (int k = 0; map[k]; k++)  {
	// 	printf("%s\n", map[k]);
	// }
	_ItterateTheMap(map, counted[1] - counted[2]);
	t_final data;
	data = _PassingTheData(head, map, counted[1]);
	close (fd);
	return (data);
}
	
	// while (head)	{
	// 	printf("---------------------------------------------\n");
	// 	printf("%s\n%s\n%s\n%s\n", head->Key, head->Value1, head->Value2, head->Value3);
	// 	printf("%d\n", head->found);
	// 	head = head->next_elem;
	// }

int*	_ReturnStatistics(char *argv)	{
	int *stats;
	int fd;
	int len;
	int jeton;
	int token;
	char *tmp;

	fd = open(argv, O_RDONLY);
	stats = malloc(3 * sizeof(int));
	ft_bzero(stats, 12);
	len = 1;
	jeton = 0; // [Maplen, line, last]
	token = 0;
	while (1)	{
		tmp = get_next_line(fd);
		// a SEGV when entring strchr or strtrim when the EOF accure
		if (tmp)    {
			if (!jeton && ft_strchr("10", ft_strtrim(tmp, " ")[0])) {
				// printf("%s\n", tmp);
				jeton = 1;
				token = 1;
				stats[2] = stats[1];
			}
			if (token)  {
				if (stats[0] < (len = ft_strlen(tmp)))
					stats[0] = len;
			}
			if (len == 0)
				break ;
			stats[1]++;
		}
		// this check if the map is emty so i should count the last line;
		else    {
			if (jeton == 0)
				stats[2] = stats[1];
			break ;
		}
		free(tmp);
	}
	// exit (0);
	close(fd);
	return (stats);
}

t_elist*	_InializeLinkedList()	{
	int		i = 0;
	t_elist *elem;
	t_elist *head;
	
	elem = malloc(sizeof(t_elist));
	head = elem;
	while (i < 6)	{
		elem->found = 0;
		elem->Key = NULL;
		elem->Value1 = NULL;
		elem->Value2 = NULL;
		elem->Value3 = NULL;
		elem->next_elem = malloc(sizeof(t_elist));
		if (i == 5)	{
			free(elem->next_elem);
			elem->next_elem = NULL;
		}
		elem = elem->next_elem;
		i++;
	}
	return (head);
}
