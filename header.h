/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:34 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/11 17:45:17 by okassimi         ###   ########.fr       */
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
	struct	s_elemlist *next_elem;
}	t_elist;

int	_ValidateInputAndFile(int argc, char *argv[]);
int _ValidateFileContent(char *argv);
int*	_ReturnStatistics(char *argv);
t_elist	*_CheckEelements(char *argv, int last);

#endif