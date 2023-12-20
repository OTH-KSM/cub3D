/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:34 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/20 16:30:11 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "fcntl.h"
# include "stdbool.h"

typedef struct	s_elemlist	{
	char	*Key;
	char	*Value1;
	char	*Value2;
	char	*Value3;
	int		found;
	int		Genre;	// 0 = Dir || 1 = Col
	struct	s_elemlist *next_elem;
}	t_elist;

typedef struct	s_FinalElem	{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
	char	**map;
	struct	s_FilanElem *next_elem;
}	t_final;

/*Validation*/
int			_ValidateInputAndFile(int argc, char *argv[]);
t_final		_ValidateFileContent(char *argv);
int*		_ReturnStatistics(char *argv);
t_elist*	_InializeLinkedList();
/*Phase01*/
t_elist		*_CheckEelements(int fd, int last);
bool		_ItMatchDir(t_elist *elem, char *sample, char **solutions, int token);
bool		_ItMatchCol(t_elist *elem, char *sample, char **solutions, int token);
int			_CheckDirValues(t_elist *elem);
int			_isDigit(char *str);
int			_CheckColValues(t_elist *elem);
/*Phase02*/
char		**_CheckMap(int fd, int maxlen, int lines, int last);
char		*_Fill(char *str, int maxlen);
/*Phase03*/
void		_ItterateTheMap(char **map, int mapL);
int			_ParsFirstLine(char **map, int mapL);
int			_ParsLastLine(char **map,int mapL);
int			_ParsMiddle(char **map, int mapL);
/*Pass Data*/
t_final		_PassingTheData(t_elist *met, char **map, int lines);
int			_RGBtoInt(int R, int G, int B);

#endif