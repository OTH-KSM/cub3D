/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 10:59:28 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	_ValidateInputAndFile(int argc, char *argv[])	{
	if (argc != 2) {
		write(2, "Error: argument\n", 16);
		return (-1);
	}
	int len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4))	{
		write(2, "Error: file extention\n", 22);
		return (-1);
	}
	if (open(argv[1], O_RDONLY) == -1)	{
		write(2, "Error: file\n", 13);
		return (-1);
	}
	return (0);
}
