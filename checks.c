/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/11 10:57:57 by okassimi         ###   ########.fr       */
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
	int length = _ReturnStatistics(argv)[0];
	int lines = _ReturnStatistics(argv)[1];
	int lastline = _ReturnStatistics(argv)[2];
	printf("length: %d\nlines: %d\nlastline: %d\n",length, lines, lastline);
	if (lines == 0)	{
		write(2, "Error: File Empty\n", 18);
		exit (1);
	}

	_CheckEelements(argv, lastline);

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
	char	*names[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int		i = 0;
	t_elist *elem;
	t_elist *head;
	
	elem = malloc(sizeof(t_elist));
	head = elem;
	while (i < 6)	{
		elem->found = 0;
		elem->Key = names[i];
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
// printf("Finishing Filling\n");
// while (head)	{
// 	printf("%s %d\n", head->Key, head->found);
// 	head = head->next_elem;
// }
// exit(0);

bool	_ItMatch(char *sample, char **solutions)	{
	int len = ft_strlen(sample);
	// printf("\"%s\"\n%s\n%s\n%s\n%s\n", sample, solutions[0], solutions[1], solutions[2], solutions[3]);
	if (len == 1 || len == 2)	{
		if (len == 1 && (sample[0] == 'F' || sample[0] == 'C'))
			return (true);
		else if (len == 2 && (!ft_strncmp(sample, solutions[0], 2) || !ft_strncmp(sample, solutions[1], 2)
		|| !ft_strncmp(sample, solutions[2], 2) || !ft_strncmp(sample, solutions[3], 2)))
			return (true);
		else
			return (false);
	}
	else
		return (false);

}


int	_CheckEelements(char *argv, int last)	{
	int fd = open(argv, O_RDONLY);
	int i = 0;
	t_elist *elem = _InializeLinkedList();
	char	**splited;
	printf("---------------------------------------------\n");
	while (i < last)	{
		splited = ft_split(get_next_line(fd), ' ');
		if (splited[0] && *splited[0] != '\n')
		{
			if (!_ItMatch(splited[0], ft_split("NO SO WE EA", ' ')))	{ // [99%] Maybe i should free the splite passed to ItMatch an of course i should free the splited
				write(2, "Wrong Type of Element\n", 22);
				exit (1);
			}
			if (!elem)	{
				write(2, "Too many Type of Elements\n", 26);	// i should also free the splitedand elem
				exit (1);
			}
			elem->Key = splited[0];
			if (splited[1])	{
				elem->Value1 = splited[1];
				if (splited[2])	{
					elem->Value2 = splited[2];
					if (splited[3])	{
						elem->Value3 = splited[3];
					}
				}
			}
			printf("%s-\n%s-\n%s-\n%s-\n", elem->Key, elem->Value1, elem->Value2, elem->Value3);
			printf("---------------------------------------------\n");
			elem = elem->next_elem;
		}
		i++;
	}
	return (0);
}

