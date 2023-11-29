/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:06:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 10:37:27 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	_check_file_extention(int argc, char *argv[])	{
	if (argc != 2) {
		write(2, "Error: argument\n", 16);
		return (-1);
	}
	int len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4))	{
		write(2, "Error: file extention\n", 22);
		return (-1);
	}
	return (0);
}
