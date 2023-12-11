/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/11 17:59:00 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int _ValidateFileContent(char *argv)	{
	// int length = _ReturnStatistics(argv)[0];
	int lines = _ReturnStatistics(argv)[1];
	int lastline = _ReturnStatistics(argv)[2];
	// printf("length: %d\nlines: %d\nlastline: %d\n",length, lines, lastline);
	if (lines == 0)	{
		write(2, "Error: File Empty\n", 18);
		exit (1);
	}
	t_elist *head = _CheckEelements(argv, lastline);
	printf("Finishing Filling\n");
	while (head)	{
		printf("---------------------------------------------\n");
		printf("%s\n%s\n%s\n%s\n", head->Key, head->Value1, head->Value2, head->Value3);
		head = head->next_elem;
	}
	exit(0);

	return (0);
}

int*	_ReturnStatistics(char *argv)	{
	int *stats;
	int fd;
	int len;
	int jeton;
	char *tmp;

	fd = open(argv, O_RDONLY);
	stats = malloc(3 * sizeof(int));
	ft_bzero(stats, 12);
	len = 1;
	jeton = 0;
	while (1)	{
		tmp = get_next_line(fd);
		if (stats[0] < (len = ft_strlen(tmp)))
			stats[0] = len;
		if (!jeton && ft_strchr("10", ft_strtrim(tmp, " ")[0])) {
			jeton = 1;
			stats[2] = stats[1];
		}
		if (len == 0)
			break ;
		stats[1]++;
	}
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


bool	_ItMatch(char *sample, char **solutions)	{
	// printf("\"%s\"\n%s\n%s\n%s\n%s\n", sample, solutions[0], solutions[1], solutions[2], solutions[3]);
	if (!ft_strncmp(sample, solutions[0], 3) || !ft_strncmp(sample, solutions[1], 3)
	|| !ft_strncmp(sample, solutions[2], 3) || !ft_strncmp(sample, solutions[3], 3))
		return (true);
	else
		return (false);
}


t_elist	*_CheckEelements(char *argv, int last)	{
	int fd = open(argv, O_RDONLY);
	int i = 0;
	t_elist *head;
	t_elist *elem = _InializeLinkedList();
	head = elem;
	char	*line;
	char	**splited;
	int		len;
	while (i < last)	{
		line = get_next_line(fd);
		if (line && line[0] != '\n')
		{
			len = ft_strlen(line);
			if (line[len - 1] == '\n')	{ // i should free the first "line"
				line = ft_substr(line, 0, len - 1);
			}
			if (elem)	{
				if (_ItMatch(line, ft_split("NO -SO -WE -EA ", '-')))	{ 
					splited = ft_split(line, ' ');
					elem->Key = splited[0];
					if (splited[1])	{
						elem->Value1 = splited[1];
						if (splited[2])	{
							write(2, "Error\nToo many Directions Arguments", 35);
							exit (0);
						}
					}
				}
				else if ((line[0] == 'F' || line[0] == 'C') && line[1] && line[1] == ' ')	{
					splited = ft_split(ft_strtrim(line + 1, " "), ',');
					elem->Key = ft_substr(line, 0, 1);
					if (splited[0])	{
						elem->Value1 = ft_strtrim(splited[0], " ");
						if (splited[1])	{
							elem->Value2 = ft_strtrim(splited[1], " ");
							if (splited[2])	{
								elem->Value3 = ft_strtrim(splited[2], " ");
								if (splited[3])	{
									write(2, "Error\nToo Many Colors Arguments\n", 33);
									exit (0);
								}
							}
						}
					}
				}
				else	{
					write(2, "Error\nWrong Type of Element\n", 28);	
					exit (1);
				}
				elem = elem->next_elem;
			}
			else	{
				write(2, "Error\nToo Many Map Type of Elements\n", 36);
				exit (1);
			}
		}
		i++;
	}
	return (head);
}

