/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:15:17 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/14 18:00:44 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	// just added 
	if (!s1 || !s2)
		return (-1);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	// ISSUE #7
	while (i < n && (ss1[i] || ss2[i]))
	{
		if (!(ss1[i] == ss2[i]))
			return (ss1[i] - ss2[i]);
		else
			i++;
	}
	return (0);
}
