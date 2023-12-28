/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fun01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:36:00 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 18:36:18 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	return_bool(char *tmp, char **solutions, bool value)
{
	free(tmp);
	free_2d_array(solutions);
	return (value);
}
