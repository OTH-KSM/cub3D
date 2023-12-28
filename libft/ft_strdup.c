/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:37:21 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 22:12:55 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;
	size_t	lens;

	i = 0;
	lens = ft_strlen(s1);
	if (!s1)
		return (0);
	p = ft_calloc((lens + 1), sizeof(char));
	if (!p)
		return (0);
	while (i < lens)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
