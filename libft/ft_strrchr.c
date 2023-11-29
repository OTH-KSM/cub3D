/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:20:03 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 10:21:54 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ca;

	i = ft_strlen(s);
	str = (char *)s;
	ca = (char )c;
	while (i >= 0)
	{
		if (str[i] == ca)
		{
			return (str + i);
		}
		i--;
	}
	return (0);
}
