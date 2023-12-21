/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phase01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:22 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/21 11:59:56 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char *_removespaces(char *str)	{
	int i = 0;
	while (str[i])	{
		if (str[i] == 'C' || str[i] == 'F')
			return (str + i);
		i++;
	}
	return (NULL);
}

t_elist	*_CheckEelements(int fd, int last)	{
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
				// TODO #8
				if (_ItMatchDir(elem, line, ft_split("NO -SO -WE -EA ", '-'), 1))	{ 
					splited = ft_split(line, ' ');
					elem->Key = splited[0];
					if (splited[1])	{
						elem->Value1 = splited[1];
						if (splited[2])	{
							write(2, "Error\nToo many Directions Arguments\n", 36);
							exit (1);
						}
					}
					elem->Genre = 0;
				}
				else if (_ItMatchCol(elem, line, ft_split("C -F ", '-'), 1) )	{
					// check if there is a comma at the beginning or at the end of the values of type of e lements
					/*this trim that is here removes the spaces after the last comma ex : "    F    ,0,255,255, "
					so because of that when i ckeck the splited i don't find that last aray*/
					// try to apply trim that removes just the first elements
					if (line[ft_strlen(line) - 1] == ',')	{						
						write(2, "Error\nToo Many Colors Arguments\n", 33);
						exit (1);
					}
					splited = ft_split((_removespaces(line) + 1), ',');
					// for (int k = 0; splited[k]; k++)	{
					// 	printf("1: %s\n", splited[k]);
					// }
					elem->Key = ft_substr(line, 0, 1);
					if (splited[0])	{
						elem->Value1 = ft_strtrim(splited[0], " ");
						if (splited[1])	{
							elem->Value2 = ft_strtrim(splited[1], " ");
							if (splited[2])	{
								elem->Value3 = ft_strtrim(splited[2], " ");
								if (splited[3])	{
									
									write(2, "Error\nToo Many Colors Arguments\n", 33);
									exit (1);
								}
							}
						}
					}
					elem->Genre = 1;
				}
				else	{
					printf("|%s|\n", line);
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
		free(line);
		i++;
	}
	elem = head;
	while (elem)	{
		// printf("%s : %d\n", elem->Key, elem->found);
		if (elem->found != 1)	{
			write(1, "Error\nMissing Elements or Elements Repetition\n", 46); // i should free someting before exiting
			exit (1);
		}
		if (elem->Genre == 0)	{
			if (_CheckDirValues(elem) == -1)
				exit (1);
		}
		else if (elem->Genre == 1)	{
			if (_CheckColValues(elem) == -1)
				exit (1);
		}
		elem = elem->next_elem;
	}
	return (head);
}

bool	_ItMatchDir(t_elist *elem, char *sample, char **solutions, int token)	{
	// printf("1: \"%s\"\n%s\n%s\n%s\n%s\n", tmp, solutions[0], solutions[1], solutions[2], solutions[3]);
	static int count[4]; // [NO, SO, WE, EA]
	char	*tmp = ft_strtrim(sample, " ");
	if (!ft_strncmp(tmp, solutions[0], 3) || !ft_strncmp(tmp, solutions[1], 3)
	|| !ft_strncmp(tmp, solutions[2], 3) || !ft_strncmp(tmp, solutions[3], 3))
	{
		if (token == 1)	{
			if (!ft_strncmp(tmp, solutions[0], 3))
				elem->found = ++(count[0]);
			else if (!ft_strncmp(tmp, solutions[1], 3))
				elem->found = ++(count[1]);
			else if  (!ft_strncmp(tmp, solutions[2], 3))
				elem->found = ++(count[2]);
			else if  (!ft_strncmp(tmp, solutions[3], 3))
				elem->found = ++(count[3]);
		}
		free(tmp);
		return (true);
	}
	else	{
		free(tmp);
		return (false);
	}
	// i shoudl free the solution because it comes allocated with split
}

bool	_ItMatchCol(t_elist *elem, char *sample, char **solutions, int token)	{
	static int count[2]; // [F, C]
	// the space before type of elements is not good -> DONE
	char	*tmp = ft_strtrim(sample, " ");
	if (!ft_strncmp(tmp, solutions[0], 2) || !ft_strncmp(tmp, solutions[1], 2))
	{
		if (token == 1) {
			if (!ft_strncmp(tmp, solutions[0], 2))
				elem->found = ++(count[0]);
			else if (!ft_strncmp(tmp, solutions[1], 2))
				elem->found = ++(count[1]);
		}
		free(tmp);
		return (true);
	}
	else	{
		free(tmp);
		return (false);
	}
	// i shoudl free the solution because it comes allocated with split
}

int	_CheckDirValues(t_elist *elem)	{
	int len;
	if (elem->Value1)	{
		len = ft_strlen(elem->Value1);
		if (len <= 4 || (len > 4 && strncmp(elem->Value1 + len - 4, ".xpm", 4)))	{
			write(2, "Error\nDirection Elements's Path Are not Valid\n", 46);
			return (-1);
		}
		else if ((open(elem->Value1, O_RDONLY)) == 	-1)	{
			write(2, "Error\nDirections Elements's Path can't open\n", 44);
			return (-1);
		}
	}
	else	{
		write(2, "Error\nMissing Directions's elements Path\n", 41);
		return (-1);
	}
	return (0);
}

int _isDigit(char *str)	{
	int i = 0;
	while (str[i])	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	_CheckColValues(t_elist *elem)	{
	int a1, a2, a3;
	if (!elem->Value1 || !elem->Value2 || !elem->Value3)	{
		write(2, "Error\nMissing Colors's elements Values\n", 39);
		return (-1);
	}
	else {
		if (_isDigit(elem->Value1) || _isDigit(elem->Value2) || _isDigit(elem->Value3))	{
			if (elem->Value1)	{printf("1: %s\n", elem->Value1);}
			if (elem->Value2)	{printf("2: %s\n", elem->Value2);}
			if (elem->Value3)	{printf("3: %s\n", elem->Value3);}
			write(2, "Error\nColors elements's Values are not digits\n", 46);
			return (-1);
		}
		a1 = ft_atoi(elem->Value1);
		a2 = ft_atoi(elem->Value2);
		a3 = ft_atoi(elem->Value3);
		if (!(a1 >= 0 && a1 <= 255) || !(a2 >= 0 && a2 <= 255) || !(a3 >= 0 && a3 <= 255))	{
			write(2, "Error\nColors elements's Values are out of range\n", 48);
			return (-1);
		}
	}
	return (0);
}
