/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:07:22 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 12:05:44 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;
	char	*p;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	p = malloc((lens1 + lens2) * (sizeof(char) + 1));
	if (!p)
		return (0);
	j = 0;
	if (i < (lens1 + lens2))
	{
		while (i < lens1)
			p[i++] = s1[j++];
		j = 0;
		while (i < (lens1 + lens2))
			p[i++] = s2[j++];
	}
	p[i] = '\0';
	free (s1);
	return (p);
}

char	*ft_gnlstrchr(char *s, int c)
{
	char	*str;
	int		i;
	char	ca;
	int		lend;

	str = (char *)s;
	i = 0;
	ca = (char)c;
	lend = ft_strlen(s);
	if (!s)
		return (0);
	while (i <= lend)
	{
		if (str[i] == ca)
			return (s + i + 1);
		i++;
	}
	return (0);
}

char	*ft_gnlsubstr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || s[i] == '\0')
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	s = s + start;
	p = malloc(len * sizeof(char) + 1);
	if (!p)
		return (0);
	while (s[i] && i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = 0;
	return (p);
}
