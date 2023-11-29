/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:28:21 by okassimi          #+#    #+#             */
/*   Updated: 2022/11/13 12:23:59 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!str && len == 0)
		return (0);
	if (to_find[i] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j] && i + j < len)
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}

int main()
{
    //char str[] = NULL;
    //char to[] = "hella";
    printf("%s", ft_strnstr("hello\nworld", "\n", 8));
    // printf("%s", ft_strnstr("hellowothman, "hello", 5));
    // printf("%s", ft_strnstr("hellowothmane", "othmanee", 30));
    // printf("%s", ft_strnstr("hellowothmane", "othmanee", 5));
    // printf("%s", ft_strnstr("hellowothmane", "owo", 5));
    // printf("%s", ft_strnstr("hellowothmane", "", 5));
    // printf("%s", ft_strnstr("hellowothmane", "hello", 25));
}